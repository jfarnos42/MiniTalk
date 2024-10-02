/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfarnos- <jfarnos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 03:39:16 by jfarnos-          #+#    #+#             */
/*   Updated: 2024/10/02 13:39:00 by jfarnos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

volatile sig_atomic_t	g_confirmed_data = 0;

static void	ft_error(char *message)
{
	ft_printf("%s\n", message);
	exit(EXIT_FAILURE);
}

int	pid_parser(char *digit)
{
	int	i;

	i = -1;
	while (digit[i])
	{
		if (!ft_isdigit(digit[i++]))
			return (FALSE);
	}
	return (TRUE);
}

void	signal_handler(int signal)
{
	if ((signal == SIGUSR1) || (signal == SIGUSR2))
		g_confirmed_data = TRUE;
}

void	send_data(pid_t server_pid, char c)
{
	int	i;

	i = 0;
	while (i < BIT_COUNT)
	{
		if (c & (1 << i))
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		i++;
		while (!g_confirmed_data)
			pause();
		g_confirmed_data = FALSE;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;
	const char			*data;

	if (argc != 3)
		ft_error("Error: ./client <server PID> <message>");
	if (pid_parser(argv[1]) == FALSE)
		ft_error("Error: server PID must be INT");
	server_pid = ft_atoi(argv[1]);
	data = argv[2];
	sa.sa_handler = &signal_handler;
	sa.sa_flags = SA_RESTART;
	sigfillset(&sa.sa_mask);
	if ((sigaction(SIGUSR1, &sa, NULL) == -1) || (sigaction(SIGUSR2, &sa,
				NULL) == -1))
		ft_error("Error: signal lost...");
	while (*data)
	{
		send_data(server_pid, *data);
		data++;
	}
	send_data(server_pid, '\0');
	return (0);
}
