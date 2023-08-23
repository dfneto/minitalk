/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:56 by davifern          #+#    #+#             */
/*   Updated: 2023/08/17 13:17:57 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
int counter_temp = 0;
char c = 0;
char msg[3];
int i = 0;

void    func(int signum)
{   
    c = c | 1;
    counter_temp++;
    if (counter_temp == 8)
    {
        ft_printf("1");
        ft_printf("%c", c);
        // msg[i] = c;
        // i++;
        counter_temp = 0;
    }
    // if (i == 3)
    // {
    //     ft_printf("%s\n", msg);
    //     i = 0;
    // }
    c = c << 1; //TODO: refletir se seria mais didático mover mask ao invés do char. Neste caso teria que ser 128?
}

void    func2(int signum)
{
    counter_temp++;
    if (counter_temp == 8)
    {
        ft_printf("1");
        ft_printf("%c", c);
        // msg[i] = c;
        // i++;
        counter_temp = 0;
    }
    // if (i == 3)
    // {
    //     ft_printf("%s\n", msg);
    //     i = 0;
    // }
    c = c << 1;
}


int main()
{
    int pid;

    pid = getpid();
    ft_printf("My pid: %d\n", pid);
    signal(SIGUSR1, func);
    signal(SIGUSR2, func2);
    while(1)
    {
        pause();   
    }
    return (0);
}