/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:35:00 by msingh            #+#    #+#             */
/*   Updated: 2026/01/31 12:48:20 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	run_rrr(t_node **a, t_node **b, t_rot *rot)
{
	while (rot->rra > 0 && rot->rrb > 0)
	{
		rrr(a, b);
		rot->rra--;
		rot->rrb--;
	}
	do_rra(a, &rot->rra);
	do_rrb(b, &rot->rrb);
}

t_rot	init_rot(t_tab *c, t_lens lens)
{
	t_rot	rot;

	rot.ra = c->target_pos_a;
	rot.rb = c->pos_b;
	rot.rra = dist_down(c->target_pos_a, lens.a);
	rot.rrb = dist_down(c->pos_b, lens.b);
	return (rot);
}

void	exec_move_mix(t_node **a, t_node **b, t_rot *rot, t_move move)
{
	if (move == MOVE_RARRB)
	{
		do_ra(a, &rot->ra);
		do_rrb(b, &rot->rrb);
	}
	else
	{
		do_rra(a, &rot->rra);
		do_rb(b, &rot->rb);
	}
}

void	exec_array_choice(t_node **a, t_node **b, t_tab *c, t_move move)
{
	t_lens	lens;
	t_rot	rot;

	lens = get_lens(*a, *b);
	rot = init_rot(c, lens);
	if (move == MOVE_RARB)
		run_rr(a, b, &rot);
	else if (move == MOVE_RRARRB)
		run_rrr(a, b, &rot);
	else
		exec_move_mix(a, b, &rot, move);
	pa(b, a);
}

void	rotate_to_min(t_node **a, int min, int pos, int len)
{
	if (pos <= len / 2)
		do_ra(a, &pos);
	else
	{
		pos = len - pos;
		do_rra(a, &pos);
	}
	while ((*a)->value != min)
		ra(a);
}
