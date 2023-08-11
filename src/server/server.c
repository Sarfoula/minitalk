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

int binary = 0;
int i = 0;

void signal_handler(int signal)
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
}

int main()
{
	int	pid;

	pid = getpid();
	printf("pid = %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1) {
	}
	return (0);
}