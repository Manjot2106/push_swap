/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:12:25 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:22:00 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*str;
	size_t			i;

	if (size != 0 && count > ((size_t) -1 / size))
		return (NULL);
	i = 0;
	str = malloc(count * size);
	if (!str)
		return (0);
	while (i < count * size)
		str[i++] = 0;
	return (str);
}
// int main ()
// {
// 	size_t count = 6;
// 	size_t size = 4;
// 	int *arr;
// 	size_t i;

// 	i = 0;
// 	arr = (int *)ft_calloc(count, size);
// 	if (!arr)
// 		return (NULL);
// 	while ( i < count )
// 	{
// 		printf("%d ", arr[i]);
// 		i++;
// 	}
// 	free(arr);
// 	return (0);
// }
