/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 14:53:36 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:23:33 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if (i >= '0' && i <= '9')
		return (1);
	return (0);
}
// int main ()
// {
// 	char ch1 = '5';
// 	char ch2 = 'z';
// 	char ch3 = '1';
// 	char ch4 = '#';

// 	printf("%d\n", ft_isascii(ch1));
// 	printf("%d\n", ft_isascii(ch2));
// 	printf("%d\n", ft_isascii(ch3));
// 	printf("%d\n", ft_isascii(ch4));
// }
