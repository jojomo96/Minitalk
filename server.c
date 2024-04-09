/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoritz < jmoritz@student.42heilbronn.d    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 00:11:39 by jmoritz           #+#    #+#             */
/*   Updated: 2024/04/09 17:44:30 by jmoritz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

#define INITIAL_BUFFER_SIZE 1024

void	print_message_and_reset(t_signal_info *signal,
		t_message_buffer *message)
{
	write(STDOUT_FILENO, message->data, message->current_size);
	message->current_size = 0;
	memset(message->data, 0, message->total_capacity);
	kill(signal->sender_pid, SIGUSR2);
	signal->sender_pid = 0;
}

void	handle_byte(t_signal_info *signal, t_message_buffer *message)
{
	char	*new_buffer;

	if (signal->current_char == '\0')
		print_message_and_reset(signal, message);
	else
	{
		if (message->current_size >= message->total_capacity - 1)
		{
			message->total_capacity *= 2;
			new_buffer = (char *)realloc(message->data,
					message->total_capacity);
			if (new_buffer == NULL)
			{
				free(message->data);
				exit(EXIT_FAILURE);
			}
			message->data = new_buffer;
		}
		message->data[message->current_size++] = signal->current_char;
	}
	signal->received_bits = 0;
	signal->current_char = 0;
	if (signal->sender_pid != 0)
		kill(signal->sender_pid, SIGUSR1);
}

void	init_message_buffer(t_message_buffer *message)
{
	message->data = (char *)malloc(message->total_capacity * sizeof(char));
	if (message->data == NULL)
		exit(EXIT_FAILURE);
	memset(message->data, 0, message->total_capacity);
}

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static t_signal_info	signal = {0, 0, 0};
	static t_message_buffer	message = {NULL, 0, INITIAL_BUFFER_SIZE};

	(void)context;
	if (message.data == NULL)
		init_message_buffer(&message);
	if (signal.sender_pid == 0)
		signal.sender_pid = info->si_pid;
	if (sig == SIGUSR1)
		signal.current_char |= (1 << signal.received_bits);
	signal.received_bits++;
	if (signal.received_bits == 8)
		handle_byte(&signal, &message);
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
