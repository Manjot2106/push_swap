/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:25:14 by msingh            #+#    #+#             */
/*   Updated: 2026/01/28 08:41:48 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_find_last(t_node *stack)
{
	if (stack == 0)
		return (0);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_max(t_node *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (stack->value > i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	ft_min(t_node *stack)
{
	int	i;

	i = stack->value;
	while (stack)
	{
		if (stack->value < i)
			i = stack->value;
		stack = stack->next;
	}
	return (i);
}

int	list_len(t_node *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		stack = stack->next;
		count++;
	}
	return (count);
}
