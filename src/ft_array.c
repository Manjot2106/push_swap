/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:34:50 by msingh            #+#    #+#             */
/*   Updated: 2026/01/31 12:47:35 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stack_to_array_b(t_node *b, t_tab *tab)
{
	int	i;

	i = 0;
	while (b)
	{
		tab[i].val = b->value;
		tab[i].pos_b = i;
		tab[i].target_pos_a = 0;
		b = b->next;
		i++;
	}
}

int	target_pos_in_a(t_node *a, int b_val, int min_pos)
{
	t_node	*cur;
	int		pos;
	int		best_val;
	int		best_pos;

	cur = a;
	pos = 0;
	best_val = INT_MAX;
	best_pos = min_pos;
	while (cur)
	{
		if (cur->value > b_val && cur->value < best_val)
		{
			best_val = cur->value;
			best_pos = pos;
		}
		pos++;
		cur = cur->next;
	}
	if (best_val == INT_MAX)
		return (min_pos);
	return (best_pos);
}

void	assign_targets_a(t_node *a, t_tab *tab, int len_b)
{
	int	i;
	int	min_pos;

	min_pos = min_pos_a(a);
	i = 0;
	while (i < len_b)
	{
		tab[i].target_pos_a = target_pos_in_a(a, tab[i].val, min_pos);
		i++;
	}
}
