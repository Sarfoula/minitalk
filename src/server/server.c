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

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../../ft_printf/ft_printf.h"

int binary = 0;
int i = 0;

void signal_handler(int signal, siginfo_t *info, void *context)
{
	binary = binary << 1;
	if (signal == 10)
		binary = binary | 1;
	i += 1;
	if (i == 8)
	{
		write(1, &binary, 1);
		i = 0;
	}
	printf("pid client == %d\n", info->si_pid);
	(void)context;
}

int main(int argc, char **argv)
{
	int	pid;
	struct sigaction test;

	(void)argv;
	if (argc != 1)
		return (ft_printf("./server takes no argument\n"), 0);
	pid = getpid();
	test.sa_sigaction = signal_handler;
	sigemptyset(&test.sa_mask);
	test.sa_flags = 0;

	ft_printf("pid = %d\n", pid);
	sigaction(SIGUSR1, &test, NULL);
	sigaction(SIGUSR2, &test, NULL);
	while (1) {
	}
	return (0);
}
