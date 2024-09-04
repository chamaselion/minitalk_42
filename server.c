/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:11:47 by bszikora          #+#    #+#             */
/*   Updated: 2024/09/04 15:29:20 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_sharevalue	g_value;

void	sig_handler(int signum)
{
	g_value.g_signal = signum;
	if (signum == SIGUSR1)
	{
		g_value.bit_buffer[g_value.bit_count++] = 1;
	}
	else if (signum == SIGUSR2)
	{
		g_value.bit_buffer[g_value.bit_count++] = 0;
	}
}

void	print_stored_bits(void)
{
	int	c;
	int	i;

	while (1)
	{
		if (g_value.bit_count >= 8)
		{
			c = 0;
			i = 0;
			while (i < 8)
			{
				c |= (g_value.bit_buffer[i] << (7 - i));
				i++;
			}
			write(1, &c, 1);
			if (c == '\0')
				write(1, "\n", 1);
			g_value.bit_count = 0;
		}
		pause();
	}
}

int	main(int argc, char **argv)
{
	int		pid;

	g_value.bit_count = 0;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf("Server PID: %d\n", pid);
		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);
		print_stored_bits();
	}
	else
		ft_printf("Usage: %s\n", argv[0]);
	return (0);
}
