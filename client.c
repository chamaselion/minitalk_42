/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 10:42:15 by bszikora          #+#    #+#             */
/*   Updated: 2024/09/04 16:10:26 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(int pid, char *message)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (1)
	{
		c = message[i];
		j = 7;
		while (j >= 0)
		{
			if (c >> j & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			j--;
		}
		if (message[i] == '\0')
			break ;
		i++;
	}
}

int	check_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc == 3)
	{
		if (check_str(argv[1]))
		{
			ft_printf("Error. Enter valid pid printed by the server\n");
			exit(0);
		}
		pid = ft_atoi(argv[1]);
		send_message(pid, argv[2]);
	}
	else
		ft_printf("Usage: %s [PID] [message]\n", argv[0]);
	return (0);
}
