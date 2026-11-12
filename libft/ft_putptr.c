/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:32:21 by msingh            #+#    #+#             */
/*   Updated: 2025/12/25 14:15:25 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_ptr_len(unsigned long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_putptr_hex(unsigned long n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		ft_putptr_hex(n / 16);
		ft_putptr_hex(n % 16);
	}
	else
		ft_putchar(base[n]);
}

int	ft_print_ptr(unsigned long ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	ft_putptr_hex(ptr);
	count += ft_ptr_len(ptr);
	return (count);
}
