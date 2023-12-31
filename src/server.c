/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifern <davifern@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 13:17:56 by davifern          #+#    #+#             */
/*   Updated: 2023/08/28 14:15:42 by davifern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_msg = NULL;

void	create_empty_message(int len)
{
	g_msg = (char *)ft_calloc(len + 1, sizeof(char));
	if (!g_msg)
		return ;
}

int	add_char_to_the_msg(char c, int *counter_temp)
{
	int	position;

	position = ft_strlen(g_msg);
	if (c)
		g_msg[position] = c;
	else
	{
		g_msg[position] = '\0';
		ft_putendl_fd(g_msg, 1);
		free(g_msg);
		*counter_temp = 0;
		return (1);
	}
	return (0);
}

void	func(int signum)
{
	static int	len = 0;
	static char	c = 0;
	static int	counter_temp = 0;

	if (++counter_temp <= 32)
	{
		if (signum == SIGUSR1)
			len = len | 1;
		if (counter_temp == 32)
			create_empty_message(len);
		len = len << 1;
	}
	else
	{
		if (signum == SIGUSR1)
			c = c | 1;
		if (counter_temp == 40)
		{
			if (add_char_to_the_msg(c, &counter_temp) == 1)
				return ;
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
