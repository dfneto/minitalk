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

void    func(int signum)
{   
    ft_printf("1");
    counter_temp++;
    // usleep(TIME_TO_SLEEP);
    if (counter_temp == 8)
    {
        ft_printf("\n");
        counter_temp = 0;
    }
}

void    func2(int signum)
{
    ft_printf("0");
    counter_temp++;
    // usleep(TIME_TO_SLEEP);
    if (counter_temp == 8)
    {
        ft_printf("\n");
        counter_temp = 0;
    }
}


int main()
{
    int pid;

    pid = getpid();
    ft_printf("My pid: %d\n", pid);
    while(1)
    {
        signal(SIGUSR1, func);
        signal(SIGUSR2, func2);
    }
    return (0);
}