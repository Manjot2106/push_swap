/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 13:41:28 by msingh            #+#    #+#             */
/*   Updated: 2025/12/25 14:14:39 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(long n)
{
	char	*base;
	int		count;

	count = 0;
	base = "0123456789";
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(base[n % 10]);
	return (count);
}

int	ft_unsignednbr(unsigned long n)
{
	char			*base;
	unsigned int	count;

	count = 0;
	base = "0123456789";
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(base[n % 10]);
	return (count);
}

int	ft_puthex(unsigned int n, char spec)
{
	char	*base;
	int		count;

	if (spec == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	count = 0;
	if (n >= 16)
		count += ft_puthex(n / 16, spec);
	count += ft_putchar(base[n % 16]);
	return (count);
}
