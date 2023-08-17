/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:40:33 by yallo             #+#    #+#             */
/*   Updated: 2023/07/27 17:40:33 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "../../ft_printf/ft_printf.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	long	result;
	int		sign;

	i = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	result = 0;
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		if (result != ((result * 10 + str[i] - 48) / 10) && sign == -1)
			return (0);
		if (result != ((result * 10 + str[i] - 48) / 10) && sign == 1)
			return (-1);
		i++;
	}
	return ((int)(result * sign));
}

int	send_bi(char symbol, int pid)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (((symbol >> i) & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
	}
	return (0);
}

int send(char *text, int pid)
{
	int	i;

	i = 0;
	while (text[i])
	{
		send_bi(text[i], pid);
		i++;
	}
	send_bi('\n', pid);
	return (0);
}

void signal_handler()
{
	ft_printf("Your message has been received !!!\n");
}

int main(int argc, char **argv)
{
	if (argc != 3)
		return (ft_printf("Use:\n./client PID \"message\"\n"), 0);
	signal(SIGUSR1, signal_handler);
	send(argv[2], ft_atoi(argv[1]));

	return (0);
}
