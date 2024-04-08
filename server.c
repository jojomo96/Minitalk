/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:11:39 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 01:07:46 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bits_received = 0;
	static char		c = 0;
	static pid_t	client_pid = 0;

	(void)context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		if (c == '\0')
		{
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		else
			write(STDOUT_FILENO, &c, 1);
		bits_received = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
