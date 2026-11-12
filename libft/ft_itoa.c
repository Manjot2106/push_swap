/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:26:40 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 18:14:45 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_len(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n <= 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*str;
	int		start;

	start = 0;
	i = ft_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = '\0';
	i--;
	if (n < 0)
	{
		str[0] = '-';
		start = 1;
		n = -n;
	}
	while (i >= start)
	{
		str[i--] = (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));

// }
