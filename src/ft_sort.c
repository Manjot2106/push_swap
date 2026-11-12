/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 12:58:14 by msingh            #+#    #+#             */
/*   Updated: 2026/01/24 13:47:36 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_node **stack_a)
{
	if (ft_max(*stack_a) == (*stack_a)->value)
		ra(stack_a);
	else if (ft_max(*stack_a) == (*stack_a)->next->value)
		rra(stack_a);
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a);
}

int	is_sorted(t_node **stack_a)
{
	t_node	*current;

	if (!stack_a || !(*stack_a)->next)
		return (1);
	current = *stack_a;
	while (current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

int	ft_find_index(t_node *stack_a, int nbr)
{
	int	i;

	i = 0;
	while (stack_a)
	{
		if (stack_a->value == nbr)
			return (i);
		stack_a = stack_a->next;
		i++;
	}
	return (-1);
}
