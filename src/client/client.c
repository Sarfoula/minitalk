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
#include <signal.h>

int	send_bi(char symbol)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if (((symbol >> i) & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		i--;
	}
	return (0);
}

int main()
{
	send_bi('A');
	//cas d'erreur
	//envoyer le msg
	//accuser de réception
	return (0);
}