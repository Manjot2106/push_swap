/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:02:06 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:23:20 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}
// int main ()
// {
// 	char ch1 = 'A';
// 	char ch2 = 'z';
// 	char ch3 = '1';
// 	char ch4 = '#';

// 	printf("%d\n", ft_isascii(ch1));
// 	printf("%d\n", ft_isascii(ch2));
// 	printf("%d\n", ft_isascii(ch3));
// 	printf("%d\n", ft_isascii(ch4));
// }
