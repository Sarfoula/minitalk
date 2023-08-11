/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 01:06:37 by yallo             #+#    #+#             */
/*   Updated: 2022/12/20 01:06:37 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr(int nbr, int *count)
{
	if (nbr == INT_MIN)
		return (ft_putstr("-2147483648", count));
	if (nbr < 0)
	{
		ft_putchar('-', count);
		nbr = -nbr;
	}
	ft_putnbr_base(nbr, 10, "0123456789", count);
}
