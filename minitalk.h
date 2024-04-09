/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:03:58 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 15:32:47 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_message_buffer
{
	char				*data;
	int					current_size;
	int					total_capacity;
}						t_message_buffer;

typedef struct s_signal_info
{
	int					received_bits;
	char				current_char;
	pid_t				sender_pid;
}						t_signal_info;

#endif
