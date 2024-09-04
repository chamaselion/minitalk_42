/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bszikora <bszikora@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:01:27 by bszikora          #+#    #+#             */
/*   Updated: 2024/09/04 14:55:07 by bszikora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_sharevalue
{
	volatile sig_atomic_t	g_signal;
	volatile sig_atomic_t	bit_count;
	char					bit_buffer[8];
}	t_sharevalue;

#endif