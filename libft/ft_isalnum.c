/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 09:37:08 by msingh            #+#    #+#             */
/*   Updated: 2025/11/10 16:22:43 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a'
			&& c <= 'z'))
		return (1);
	return (0);
}
// int main ()
// {
// 	char ch1 = 'A';
// 	char ch2 = '1';
// 	char ch3 = '#';

// 	printf("%d\n", ft_isalnum(ch1));
// 	printf("%d\n", ft_isalnum(ch2));
// 	printf("%d\n", ft_isalnum(ch3));
// }
