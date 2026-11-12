/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:35:09 by msingh            #+#    #+#             */
/*   Updated: 2026/01/31 12:50:14 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_sort_b(t_node **a, t_node **b)
{
	int	mean;

	while (list_len(*a) > 3 && !is_sorted(a))
	{
		mean = calc_mean(*a);
		pb(a, b);
		if (*b && (*b)->value > mean)
			rb(b);
	}
}

void	push_sort_a(t_node **a, t_node **b)
{
	t_tab	*tab;
	t_lens	lens;
	t_best	best;

	while (*b)
	{
		lens = get_lens(*a, *b);
		tab = malloc(sizeof(t_tab) * lens.b);
		if (!tab)
			return ;
		stack_to_array_b(*b, tab);
		assign_targets_a(*a, tab, lens.b);
		best = pick_best_array_move(tab, get_lens(*a, *b));
		exec_array_choice(a, b, &tab[best.idx], best.move);
		free(tab);
	}
}

void	sort_b(t_node **stack_a, t_node **stack_b)
{
	while (list_len(*stack_b) < 2 && list_len(*stack_a) > 3
		&& !is_sorted(stack_a))
		pb(stack_a, stack_b);
	if (list_len(*stack_a) > 3 && !is_sorted(stack_a))
		push_sort_b(stack_a, stack_b);
	if (!is_sorted(stack_a))
		ft_sort_three(stack_a);
}

void	finish_rotate(t_node **a)
{
	t_lens	lens;
	int		min;
	int		pos;

	lens = get_lens(*a, NULL);
	min = ft_min(*a);
	pos = min_pos_a(*a);
	rotate_to_min(a, min, pos, lens.a);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	sort_b(stack_a, stack_b);
	push_sort_a(stack_a, stack_b);
	finish_rotate(stack_a);
}
