/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 16:32:44 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:42:12 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	t;
	int		i;

	i = 0;
	t = (char)c;
	while (str[i])
	{
		if (str[i] == t)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (0);
}
// int main()
// {
// 	const char str[] = "Hello, World!";
// 	char ch = 'W';
// 	char *result = ft_strchr(str, ch);
// 	printf("Character found: %s\n", result);
// }
