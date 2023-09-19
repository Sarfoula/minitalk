/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 09:38:03 by yallo             #+#    #+#             */
/*   Updated: 2023/07/03 09:38:03 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "../../ft_printf/ft_printf.h"

int binary = 0;
int i = 0;

void signal_handler(int signal, siginfo_t *info, void *context)
{
	char	received;
	binary = binary << 1;
	if (signal == SIGUSR1)
		binary = binary | 1;
	i++;
	if (i == 8)
	{
		received = (char)binary;
		write(1, &received, 1);
		kill(info->si_pid, SIGUSR1);
		i = 0;
		binary = 0;
	}
	(void)context;
}

int main(int argc, char **argv)
{
	int	pid;
	struct sigaction sa;

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
	while (1) {
	}
	return (0);
}
