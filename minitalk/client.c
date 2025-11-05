/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:00:43 by arpereir          #+#    #+#             */
/*   Updated: 2025/11/05 14:55:29 by arpereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <signal.h>
#include "libft/libft.h"

int	g_flag = 0;

void	signal_handler(int sig)
{
	(void)sig;
	g_flag = 1;
}

static void	send_signal(int pid, int sig)
{
	if (kill(pid, sig) == -1)
	{
		ft_printf("Invalid PID!\n");
		exit(1);
	}
}

void	send_bits(int pid, char c)
{
	int	bit;
	int	i;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		g_flag = 0;
		if (bit == 1)
			send_signal(pid, SIGUSR1);
		else
			send_signal(pid, SIGUSR2);
		while (!g_flag)
			pause();
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
	{
		ft_printf("Argc should be 3!\n");
		return (1);
	}
	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Invalid PID!\n");
		return (-1);
	}
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
