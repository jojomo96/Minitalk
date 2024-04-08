/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:15:54 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 01:08:48 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		usleep(100);
		i++;
	}
}

void	send_string(pid_t pid, char *str)
{
	while (*str)
	{
		send_char(pid, *str);
		str++;
	}
	send_char(pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc != 3)
	{
		printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	pid = atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
