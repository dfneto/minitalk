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

int main(int argc, char *argv[])
{
    int     pid;
    char    *msg;

    if (argc == 3)
    {
        pid = get_pid(argv[1]);
        if (!pid)
        {
            print_error("INVALID PID");
            return (1);
        }
        ft_printf("My pid is %d\n", pid);
    }
    return (0);
}
