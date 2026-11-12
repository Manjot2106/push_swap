/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_rot_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:35:04 by msingh            #+#    #+#             */
/*   Updated: 2026/01/28 09:14:57 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	do_ra(t_node **a, int *n)
{
	while (*n > 0)
	{
		ra(a);
		(*n)--;
	}
}

void	do_rb(t_node **b, int *n)
{
	while (*n > 0)
	{
		rb(b);
		(*n)--;
	}
}

void	do_rra(t_node **a, int *n)
{
	while (*n > 0)
	{
		rra(a);
		(*n)--;
	}
}

void	do_rrb(t_node **b, int *n)
{
	while (*n > 0)
	{
		rrb(b);
		(*n)--;
	}
}

void	run_rr(t_node **a, t_node **b, t_rot *rot)
{
	while (rot->ra > 0 && rot->rb > 0)
	{
		rr(a, b);
		rot->ra--;
		rot->rb--;
	}
	do_ra(a, &rot->ra);
	do_rb(b, &rot->rb);
}
