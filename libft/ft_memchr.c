/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:21:40 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:24:56 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned const char	*str;
	char				l;

	i = 0;
	l = (char)c;
	str = (unsigned const char *)s;
	while (i < n)
	{
		if (str[i] == l)
		{
			return ((void *)str + i);
		}
		i++;
	}
	return (0);
}
// int main ()
// {
// 	const char str[] = "Hello World!";
// 	int c = 'W';
// 	size_t n = 12;
// 	char *ret;

// 	ret = (char *)ft_memchr(str, c, n);
// 	printf("%s\n", ret);
// }
