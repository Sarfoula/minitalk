/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:02:57 by yallo             #+#    #+#             */
/*   Updated: 2022/12/20 11:19:50 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s, int *count)
{
	size_t	i;

	i = 0;
	if (!s)
		return (ft_putstr("(null)", count));
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}
