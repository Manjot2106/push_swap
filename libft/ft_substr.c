/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:27:15 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:50:22 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_checkstr(char const *s, unsigned int start)
{
	size_t	l;
	char	*str;

	l = ft_strlen(s);
	if (start >= l)
	{
		str = malloc(1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	return (0);
}

static int	ft_checkint(char const *s, unsigned int start, size_t len)
{
	int	slen;

	slen = ft_strlen(s);
	if (len > slen - start)
		len = slen - start;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;
	size_t	j;

	str = ft_checkstr(s, start);
	if (str)
		return (str);
	len = ft_checkint(s, start, len);
	i = 0;
	j = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		if (i == start)
		{
			while (j < len && s[i])
				str[j++] = s[i++];
			str[j] = '\0';
			return (str);
		}
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int main ()
// {
// 	char *str;
// 	str = ft_substr("helloollehhello", 0, 0);
// 	printf("%s", str);
// 	free(str);
// }
