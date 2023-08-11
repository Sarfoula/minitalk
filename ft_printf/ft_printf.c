/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 11:32:03 by yallo             #+#    #+#             */
/*   Updated: 2022/12/19 13:36:05 by yallo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_arg(char c, va_list arg, int *count)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), count);
	if (c == 's')
		ft_putstr(va_arg(arg, char *), count);
	if (c == 'p')
	{
		ft_putstr("0x", count);
		ft_putnbr_base(va_arg(arg, long long unsigned int), 16, \
		"0123456789abcdef", count);
	}
	if ((c == 'd' || c == 'i'))
		ft_putnbr(va_arg(arg, int), count);
	if (c == 'u')
		ft_putnbr_base(va_arg(arg, unsigned int), 10, "0123456789", count);
	if (c == 'x')
		ft_putnbr_base(va_arg(arg, unsigned int), 16, \
		"0123456789abcdef", count);
	if (c == 'X')
		ft_putnbr_base(va_arg(arg, unsigned int), 16, \
		"0123456789ABCDEF", count);
	if (c == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			check_arg(format[i], arg, &count);
		}
		else
			ft_putchar(format[i], &count);
		i++;
	}
	va_end(arg);
	return (count);
}
