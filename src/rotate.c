/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:56:34 by msingh            #+#    #+#             */
/*   Updated: 2026/01/24 14:03:16 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_node **stack)
{
	t_node	*first_node;
	t_node	*last_node;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	first_node = *stack;
	last_node = ft_find_last(*stack);
	last_node->next = first_node;
	first_node->prev = last_node;
	*stack = first_node->next;
	(*stack)->prev = NULL;
	first_node->next = NULL;
}

void	ra(t_node **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_node **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_node **stack_a, t_node **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
