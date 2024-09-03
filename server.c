/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:11:47 by bszikora          #+#    #+#             */
/*   Updated: 2024/09/03 11:33:58 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_signal;

void	sig_handler(int signum)
{
	g_signal = signum;
}

int	main(void)
{
	int		pid;
	char	c;
	int		i;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	while (1)
	{
		c = 0;
		i = 0;
		while (i < 8)
		{
			signal(SIGUSR1, sig_handler);
			signal(SIGUSR2, sig_handler);
			pause();
			if (g_signal == SIGUSR1)
				c |= 1 << i;
			i++;
		}
		if (c == '\0')
			ft_putchar_fd('\n', 1);
		else
			ft_putchar_fd(c, 1);
	}
	return (0);
}