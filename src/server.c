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

char 	*create_empty_message(int len)
{
	char	*msg;

	ft_printf(".......................creating malloc of %d\n", len);

	msg = (char *)ft_calloc(len + 1, sizeof(char));
	if (!msg)
		return (0);
	// int i = 0;
	// while(i < 100000)
	// {
	// 	msg[i] = 'a';
	// 	i++;
	// }
	// // msg[0] = 'd';
	// // msg[1] = 'd';
	// // msg[2] = 'd';
	// // msg[3] = 'd';
	// // msg[4] = 'd';
	// ft_printf("message: %s\n", msg);
	// ft_printf("waka\n");
	return (msg);
}

void	add_char_to_the_string(char *msg, char c, int *counter_temp)
{
	int	position;

	position = ft_strlen(msg);
	
	// ft_printf("first position: %d\n", position);
	// ft_printf("adding the char: %c\n", c);
	// ft_printf("message: %s\n", *msg);
	ft_printf("--add_char_to_the_string---\n");
	
	if (c)
		msg[position] = c;
	else
	{
		msg[position] = '\0';
		ft_putendl_fd(msg, 1);
		free(msg);
		*counter_temp = 0;
		return ;
	}
}
			// if (c)
			// {
			// 	// ft_printf("%p\n", msg);
			// 	msg[ft_strlen(msg)] = c;
			// }
			// else
			// {
			// 	msg[ft_strlen(msg)] = '\0';
			// 	ft_putendl_fd(msg, 1);
			// 	free(msg);
			// 	counter_temp = 0;
			// 	return ;
			// }

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
			msg = create_empty_message(len);
		len = len << 1;
	}
	else
	{
		if (signum == SIGUSR1)
			c = c | 1;
		if (counter_temp == 40)
		{
			add_char_to_the_string(msg, c, &counter_temp);
			// if (c)
			// {
			// 	// ft_printf("%p\n", msg);
			// 	msg[ft_strlen(msg)] = c;
			// }
			// else
			// {
			// 	msg[ft_strlen(msg)] = '\0';
			// 	ft_putendl_fd(msg, 1);
			// 	free(msg);
			// 	counter_temp = 0;
			// 	return ;
			// }
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
