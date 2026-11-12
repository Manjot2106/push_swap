/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:18:37 by msingh            #+#    #+#             */
/*   Updated: 2025/11/08 12:39:16 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *tab1, const char *tab2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (tab2[j] == '\0')
		return ((char *)tab1);
	while (tab1[i] && i < n)
	{
		j = 0;
		while (i + j < n && tab1[i + j] == tab2[j])
		{
			if (tab2[j + 1] == '\0')
				return ((char *)tab1 + i);
			j++;
		}
		i++;
	}
	return (0);
}
