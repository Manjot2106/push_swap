/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:06:10 by msingh            #+#    #+#             */
/*   Updated: 2026/01/28 09:20:02 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	parse_int(char *str)
{
	long	result;
	int		sign;
	int		i;
	int		digit;

	result = 0;
	sign = 1;
	i = 0;
	if (!check_syntax(str, &sign))
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		digit = str[i] - '0';
		result = result * 10 + digit;
		if (sign == 1 && result > INT_MAX)
			return (0);
		if (sign == -1 && result > (long)INT_MAX + 1)
			return (0);
		i++;
	}
	return (1);
}

int	check_syntax(char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*sign = -1;
		i++;
		if (str[i] == '\0')
			return (0);
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	not_duplicate(t_node *stack, int nbr)
{
	if (!stack)
		return (1);
	while (stack)
	{
		if (stack->value == nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}
