/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheapest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 08:34:53 by msingh            #+#    #+#             */
/*   Updated: 2026/01/31 12:48:05 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	compute_array_costs(t_tab *c, t_lens lens, int costs[4])
{
	int	up_a;
	int	down_a;
	int	up_b;
	int	down_b;

	up_a = c->target_pos_a;
	down_a = dist_down(c->target_pos_a, lens.a);
	up_b = c->pos_b;
	down_b = dist_down(c->pos_b, lens.b);
	costs[0] = max_int(up_a, up_b);
	costs[1] = max_int(down_a, down_b);
	costs[2] = up_a + down_b;
	costs[3] = down_a + up_b;
}

void	scan_costs(int costs[4], int idx, t_best *best)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (costs[j] < best->cost)
		{
			best->cost = costs[j];
			best->idx = idx;
			best->move = (t_move)j;
		}
		j++;
	}
}

t_best	pick_best_array_move(t_tab *tab, t_lens lens)
{
	int		i;
	int		costs[4];
	t_best	best;

	best.cost = INT_MAX;
	best.idx = 0;
	best.move = MOVE_RARB;
	i = 0;
	while (i < lens.b)
	{
		compute_array_costs(&tab[i], lens, costs);
		scan_costs(costs, i, &best);
		i++;
	}
	return (best);
}
