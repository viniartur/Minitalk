/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvieira <vvieira@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 20:09:26 by vvieira           #+#    #+#             */
/*   Updated: 2025/11/20 20:09:28 by vvieira          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_ack = 0;

static void	ack_handler(int signal)
{
	if (signal == SIGUSR1)
		g_ack = 1;
}

static void	send_bit(pid_t id, char bit)
{
	g_ack = 0;
	if (bit)
		kill(id, SIGUSR1);
	else
		kill(id, SIGUSR2);
	while (!g_ack)
		pause();
}

static void	send_char(pid_t id, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		send_bit(id, (c >> i) & 1);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	pid_t	server_id;
	int		i;

	if (argc == 3)
	{
		signal(SIGUSR1, ack_handler);
		server_id = ft_atoi(argv[1]);
		if (kill(server_id, 0) == -1)
		{
			ft_printf("\033[1;31m❌ Server PID %d incorrect!\033[0m\n",
				server_id);
			return (1);
		}
		i = 0;
		while (argv[2][i])
		{
			send_char(server_id, argv[2][i]);
			i++;
		}
		send_char(server_id, '\0');
		ft_printf("\033[1;32m✅ Message sent successfully!\033[0m\n");
	}
	else
		ft_printf("\033[1;31m❌ Usage: ./client <PID> <message>\033[0m\n");
	return (0);
}
