/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:38:03 by yallo             #+#    #+#             */
/*   Updated: 2023/09/27 13:06:32 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../ft_printf/ft_printf.h"

int	g_index = 0;

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	int		binary;
	char	received;

	if (g_index == 0)
		binary = 0;
	binary = binary << 1;
	if (signal == SIGUSR1)
		binary = binary | 1;
	g_index++;
	if (g_index == 8)
	{
		g_index = 0;
		received = (char)binary;
		write(1, &received, 1);
		if (received == '\n')
			kill(info->si_pid, SIGUSR2);
	}
	kill(info->si_pid, SIGUSR1);
	(void)context;
}

int	main(int argc, char **argv)
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc != 1)
		return (ft_printf("Use: No argument\n./server\n"), 0);
	pid = getpid();
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	ft_printf("pid = %d\n", pid);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
	}
	return (0);
}
