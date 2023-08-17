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

void    func(int signum)
{
    ft_printf("Signal received 1: %d\n", signum);
}

void    func2(int signum)
{
    ft_printf("Signal received 2: %d\n", signum);
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