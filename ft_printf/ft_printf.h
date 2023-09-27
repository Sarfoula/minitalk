/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yallo <yallo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:10:16 by yallo             #+#    #+#             */
/*   Updated: 2023/09/26 12:58:37 by yallo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

int		ft_printf(const char *format, ...);
void	check_arg(char c, va_list arg, int *count);
void	ft_putchar(int c, int *count);
void	ft_putnbr_base(long long unsigned int nbr, long long unsigned int size, \
char *base, int *count);
void	ft_putnbr(int nbr, int *count);
void	ft_putstr(char *s, int *count);

#endif