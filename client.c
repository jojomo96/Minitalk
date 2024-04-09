/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:15:54 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 17:24:56 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	acknowledgment_handler(int sig)
{
	(void)sig;
	// if (sig == SIGUSR2)
	// 	write(STDOUT_FILENO, "Server received message\n", 25);
	g_ack_received = 1;
}

void	send_char(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_ack_received = 0;
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		while (!g_ack_received)
		{
			pause();
		}
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
	pid_t				pid;
	struct sigaction	sa;

	if (argc != 3)
	{
		printf("Usage: %s <PID> <message>\n", argv[0]);
		return (1);
	}
	sa.sa_flags = 0;
	sa.sa_handler = acknowledgment_handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = atoi(argv[1]);
	send_string(pid, argv[2]);
	return (0);
}
