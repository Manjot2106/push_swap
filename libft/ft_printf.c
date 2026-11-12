/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:27:07 by msingh            #+#    #+#             */
/*   Updated: 2025/12/25 14:16:06 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkformat(char spec, va_list arg)
{
	if (spec == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (spec == '%')
		return (ft_putchar('%'));
	else if (spec == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (spec == 'd' || spec == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (spec == 'u')
		return (ft_unsignednbr(va_arg(arg, unsigned int)));
	else if (spec == 'x' || spec == 'X')
		return (ft_puthex(va_arg(arg, unsigned int), spec));
	else if (spec == 'p')
		return (ft_print_ptr(va_arg(arg, unsigned long)));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			count += ft_checkformat(*format, arg);
		}
		else
			count += ft_putchar(*format);
		format++;
	}
	va_end(arg);
	return (count);
}
