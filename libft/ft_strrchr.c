/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 07:38:30 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:46:42 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	t;
	int		i;

	i = 0;
	while (s[i])
		i++;
	if ((char)c == '\0')
		return ((char *)&s[i]);
	t = (char)c;
	while (i > 0)
	{
		i--;
		if (s[i] == t)
			return ((char *)&s[i]);
	}
	return (0);
}
// int main ()
// {
// 	const char str[] = "Hello, World!";
// 	char ch = 'o';
// 	char *result = ft_strrchr(str, ch);
// 	printf(" %s\n", result);
// }
