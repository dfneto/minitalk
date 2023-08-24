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
int c = 0;
int i = 0;
int len;

void    func_()
{
    ft_printf("Waka waka 1");
}

void    func2_()
{
    ft_printf("Waka waka 2");
}

void    func(int signum)
{   
    c = c | 1;
    counter_temp++;
    if (counter_temp == 32)
    {
        len = c;
        ft_printf("%d", len);
        ft_printf("\n");
        counter_temp = 0;
        signal(SIGUSR1, SIG_DFL);
        signal(SIGUSR2, SIG_DFL);
        signal(SIGUSR1, func_);
        signal(SIGUSR2, func2_);
    }
    c = c << 1; //TODO: se eu mover mask ao invés do char. Neste caso teria que ser 128?
}

void    func2(int signum)
{
    counter_temp++;
    if (counter_temp == 32)
    {
        len = c;
        ft_printf("%d", len);
        ft_printf("\n");
        counter_temp = 0;
        signal(SIGUSR1, SIG_DFL);
        signal(SIGUSR2, SIG_DFL);
        signal(SIGUSR1, func_);
        signal(SIGUSR2, func2_);
    }
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
        pause();   //TODO: colocar as declaracoes de signal aqui e testar o consumo de memoria sem o pause
    }
    return (0);
}