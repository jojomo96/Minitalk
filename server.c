/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:11:39 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 14:59:18 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define INITIAL_BUFFER_SIZE 2
// #define MESSAGE_LIMIT 2 // Server will exit after receiving this many messages

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int		bits_received = 0;
	static char		c = 0;
	static pid_t	client_pid = 0;
	static char		*buffer = NULL;
	static int		buffer_index = 0;
	static int		buffer_size = INITIAL_BUFFER_SIZE;
	char			*new_buffer;

	// static int message_count = 0; // Count of messages received
	(void)context;
	if (buffer == NULL)
	{
		buffer = (char *)malloc(buffer_size * sizeof(char));
		if (buffer == NULL)
			exit(EXIT_FAILURE);
		memset(buffer, 0, buffer_size);
	}
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (1 << bits_received);
	bits_received++;
	if (bits_received == 8)
	{
		if (c == '\0')
		{
			write(STDOUT_FILENO, buffer, buffer_index);
			// message_count++; // Increment message count
			// if (message_count >= MESSAGE_LIMIT)
			// {
			// 	free(buffer);
			// 	printf("\nMessage limit reached. Exiting.\n");
			// 	exit(EXIT_SUCCESS);
			// }
			// Reset for next message
			buffer_index = 0;
			memset(buffer, 0, buffer_size);
			kill(client_pid, SIGUSR1);
			client_pid = 0;
		}
		else
		{
			if (buffer_index >= buffer_size - 1)
			{
				buffer_size *= 2;
				new_buffer = (char *)realloc(buffer, buffer_size);
				if (new_buffer == NULL)
				{
					free(buffer);
					exit(EXIT_FAILURE);
				}
				buffer = new_buffer;
			}
			buffer[buffer_index++] = c;
		}
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
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}
