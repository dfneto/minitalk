/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:18:00 by davifern          #+#    #+#             */
/*   Updated: 2023/08/17 13:18:00 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int get_pid(char *pid)
{
    int i;

    i = 0;
    while(pid[i])
    {
        if (!ft_isdigit(pid[i]))
            return (0);
        i++;
    }
    return ft_atoi(pid);
}

void    send_char(char c, int pid)
{
    int mask;
    int i;
    ft_printf("Size message in int : %d\n", c);
    i = 0;
    mask = 128;
    while (i <= 7)
    {
        if (c & mask)
        {
            kill(pid, SIGUSR1);
            // printf("1");
        }
        else
        {
            kill(pid, SIGUSR2);
            // printf("0");
        }
        mask = mask >> 1; //TODO: mover C e nao mask
        i++;
        usleep(TIME_TO_SLEEP);
    }
}

void    send_message(char *msg, int pid)
{
    while(*msg)
    {
        send_char(*msg, pid);
        msg++;
    }
}

void    send_size_message(int len, int pid)
{
    int i;
    long mask;
    
    ft_printf("Size message in int : %d\n", len); 
    i = 0;
    mask = 2147483648;
    while (i <= 31)
    {
        if (len & mask)
        {
            ft_printf("1");
            kill(pid, SIGUSR1);
        }
        else
        {
            ft_printf("0");
            kill(pid, SIGUSR2);
        }
        len = len << 1;
        i++;
        usleep(TIME_TO_SLEEP);
    }
}

int main(int argc, char *argv[])
{
    int     pid;

    if (argc == 3)
    {
        pid = get_pid(argv[1]);
        if (!pid)
        {
            print_error("INVALID PID");
            return (1);
        }
        send_size_message(ft_strlen(argv[2]), pid);
        //send_message(argv[2], pid);
    }
    return (0);
}