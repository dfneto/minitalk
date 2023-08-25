/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:56 by davifern          #+#    #+#             */
/*   Updated: 2023/08/25 12:47:30 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	func(int signum)
{
	static int	len = 0;
	static char	c = 0;
	static char	*msg = NULL;
	static int	counter_temp = 0;

	counter_temp++;
	if (counter_temp <= 32)
	{
		if (signum == SIGUSR1)
			len = len | 1;
		if (counter_temp == 32)
		{
			msg = (char *)ft_calloc(len + 1, sizeof(char));
			if (!msg)
				return ;
			len = 0;
		}
		len = len << 1;
	}
	else
	{
		if (signum == SIGUSR1)
			c = c | 1;
		if (counter_temp == 40)
		{
			if (c)
				msg[ft_strlen(msg)] = c;
			else
			{
				msg[ft_strlen(msg)] = '\0';
				ft_putendl_fd(msg, 1);
				free(msg);
				counter_temp = 0;
				return ;
			}
			counter_temp = 32;
			c = 0;
		}
		c = c << 1;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("My pid: %d\n", pid);
	signal(SIGUSR1, func);
	signal(SIGUSR2, func);
	while (1)
		pause();
	return (0);
}
