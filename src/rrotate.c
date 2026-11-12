/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 08:43:37 by msingh            #+#    #+#             */
/*   Updated: 2026/01/24 14:04:03 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = ft_find_last(*stack);
	last_node->next = first_node;
	first_node->prev = last_node;
	*stack = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
}

void	rra(t_node **stack_a)
{
	rrotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_node **stack_b)
{
	rrotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_node **stack_a, t_node **stack_b)
{
	rrotate(stack_a);
	rrotate(stack_b);
	ft_printf("rrr\n");
}
