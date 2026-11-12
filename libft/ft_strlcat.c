/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:48:00 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 09:07:43 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	size_d;
	size_t	size_s;
	size_t	i;

	i = 0;
	size_d = 0;
	size_s = 0;
	while (dst[size_d] && size_d < size)
		size_d++;
	while (src[size_s])
		size_s++;
	if (size <= size_d)
		return (size + size_s);
	while (src[i] && size_d + i < size - 1)
	{
		dst[size_d + i] = src[i];
		i++;
	}
	dst[size_d + i] = '\0';
	return (size_d + size_s);
}

// int	main(void)
// {
// 	char	dst[] = {"hello"};
// 	char	src[] = {"a toi"};

// 	printf("%d", ft_strlcat(dst, src, 3));
// }
