/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 11:11:47 by bszikora          #+#    #+#             */
/*   Updated: 2024/09/03 13:47:49 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

volatile sig_atomic_t	g_signal;
volatile sig_atomic_t	bit_count = 0;
char					bit_buffer[8];

void	sig_handler(int signum)
{
	g_signal = signum;
	if (signum == SIGUSR1)
	{
		bit_buffer[bit_count++] = 1;
	}
	else if (signum == SIGUSR2)
	{
		bit_buffer[bit_count++] = 0;
	}
}

int	main(int argc, char **argv)
{
	int pid;
	char c;
	int i;

	if (argc == 1)
	{
		pid = getpid();
		printf("Server PID: %d\n", pid);

		signal(SIGUSR1, sig_handler);
		signal(SIGUSR2, sig_handler);

		while (1)
		{
			if (bit_count >= 8)
			{
				c = 0;
				for (i = 0; i < 8; i++)
				{
					c |= (bit_buffer[i] << (7 - i));
				}
				write(1, &c, 1);
				bit_count = 0;
			}
			pause();
		}
	}
	else
	{
		printf("Usage: %s\n", argv[0]);
	}

	return (0);
}