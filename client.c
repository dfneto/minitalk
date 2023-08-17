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

char    *create_the_message_to_send(char *str)
{
    
    return "";
}

int get_pid(char *pid)
{
   

    while(pid)
    {

    }
    return ft_atoi(pid);
}

int main(int argc, char *argv[])
{
    int     pid;
    char    *str;

    ft_printf("WAKA\n");
    if (argc > 2)
    {
        pid = get_pid(argv[1]);
        if (!pid)
            return (1);
    }
    return (0);
}
