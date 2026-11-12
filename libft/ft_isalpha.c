/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 15:02:25 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:23:05 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// int main ()
// {
// 	char ch1 = 'A';
// 	char ch2 = 'z';
// 	char ch3 = '1';
// 	char ch4 = '#';

// 	printf("%d\n", ft_isalpha(ch1));
// 	printf("%d\n", ft_isalpha(ch2));
// 	printf("%d\n", ft_isalpha(ch3));
// 	printf("%d\n", ft_isalpha(ch4));
// }
