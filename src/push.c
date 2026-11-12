/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 13:52:17 by msingh            #+#    #+#             */
/*   Updated: 2026/01/24 14:00:43 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_node **src_stack, t_node **dst_stack)
{
	t_node	*src_tmp;

	if (!src_stack || !(*src_stack))
		return ;
	src_tmp = *src_stack;
	*src_stack = src_tmp->next;
	if (*src_stack)
		(*src_stack)->prev = NULL;
	src_tmp->next = *dst_stack;
	src_tmp->prev = NULL;
	if (*dst_stack)
		(*dst_stack)->prev = src_tmp;
	*dst_stack = src_tmp;
}

void	pa(t_node **src_stack, t_node **dst_stack)
{
	push(src_stack, dst_stack);
	ft_printf("pa\n");
}

void	pb(t_node **src_stack, t_node **dst_stack)
{
	push(src_stack, dst_stack);
	ft_printf("pb\n");
}
