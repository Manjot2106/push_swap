/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:28:28 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 10:35:58 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scan(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	while (s1[i])
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i++;
	}
	return (i);
}

static int	ft_rscan(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = ft_strlen(s1);
	i--;
	while (i >= 0)
	{
		j = 0;
		while (set[j])
		{
			if (s1[i] == set[j])
				break ;
			j++;
		}
		if (s1[i] != set[j])
			break ;
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = ft_scan(s1, set);
	j = ft_rscan(s1, set);
	if (j - i < 0)
		return (ft_calloc(1, sizeof(char)));
	str = ft_substr(s1, i, j - i);
	if (!str)
		return (NULL);
	return (str);
}

// #include <stdio.h>

// int main ()
// {
// 	char *c;
// 	c = ft_strtrim("hhggbonjourghghhhhg", "gh");
// 	printf("%s", c);
// }
