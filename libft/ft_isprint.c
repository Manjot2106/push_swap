/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:56:35 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:23:45 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
// int main ()
// {
// 	char ch1 = 'A';
// 	char ch2 = '\t';
// 	char ch3 = '1';
// 	char ch4 = '\n';

// 	printf("%d\n", ft_isascii(ch1));
// 	printf("%d\n", ft_isascii(ch2));
// 	printf("%d\n", ft_isascii(ch3));
// 	printf("%d\n", ft_isascii(ch4));
// }
