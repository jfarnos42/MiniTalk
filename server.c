/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:39:37 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/02 05:29:04 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/minitalk.h"

volatile sig_atomic_t	recived_data = 0;

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static int		bit_count = 0;
	static pid_t	client_pid = 0;

	(void)context;
	client_pid = info->si_pid;
	if (signal == SIGUSR1)
		recived_data |= (0 << bit_count);
	else if (signal == SIGUSR2)
		recived_data |= (1 << bit_count);
	bit_count++;
	kill(client_pid, SIGUSR1);
	if (bit_count == 8)
	{
		if (recived_data == '\0')
		{
			kill(client_pid, SIGUSR2);
			ft_printf("\n");
		}
		else
			ft_printf("%c", recived_data);
		bit_count = 0;
		recived_data = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server listening on PID: [ %d ]\n", getpid());
	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigfillset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, NULL) == -1) || (sigaction(SIGUSR2, &sa,
				NULL) == -1))
	{
		ft_printf("Error: signal lost...");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		pause();
	}
	return (0);
}
