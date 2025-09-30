/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arpereir <arpereir@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:00:43 by arpereir          #+#    #+#             */
/*   Updated: 2025/09/30 17:22:46 by arpereir         ###   ########.fr       */
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
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_flag)
			pause();
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	signal(SIGUSR1, signal_handler);
	pid = ft_atoi(argv[1]);
	i = 0;
	while (argv[2][i] != '\0')
	{
		send_bits(pid, argv[2][i]);
		i++;
	}
	send_bits(pid, '\0');
	return (0);
}
