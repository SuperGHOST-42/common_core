/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgutterr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:49:28 by hgutterr          #+#    #+#             */
/*   Updated: 2025/07/03 00:49:28 by hgutterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"
#include <signal.h>

static void	ft_ack_handler(int sig)
{
	(void) sig;
}

static void	ft_send_bits(int pid, unsigned char c, sigset_t *old)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c & (0x01 << bit)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		sigsuspend(old);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	sigset_t			old;
	sigset_t			block;
	int					pid;
	int					i;

	i = 0;
	sigemptyset(&block);
	sigaddset(&block, SIGUSR1);
	sigprocmask(SIG_BLOCK, &block, &old);
	sa.sa_handler = ft_ack_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	if (argc != 3)
		return (ft_printf("\033[91mError: wrong format.\033[0m\n"), 1);
	pid = ft_atoi(argv[1]);
	while (argv[2][i] != '\0')
	{
		ft_send_bits(pid, argv[2][i], &old);
		i++;
	}
	ft_send_bits(pid, '\n', &old);
	return (0);
}
