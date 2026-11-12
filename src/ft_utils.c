/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 09:15:39 by msingh            #+#    #+#             */
/*   Updated: 2026/01/28 09:15:41 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_int(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	dist_down(int pos, int len)
{
	if (pos == 0)
		return (0);
	return (len - pos);
}

t_lens	get_lens(t_node *a, t_node *b)
{
	t_lens	lens;

	lens.a = list_len(a);
	if (b)
		lens.b = list_len(b);
	else
		lens.b = 0;
	return (lens);
}

int	calc_mean(t_node *a)
{
	long	sum;
	int		len;

	sum = 0;
	len = 0;
	while (a)
	{
		sum += a->value;
		len++;
		a = a->next;
	}
	if (len == 0)
		return (0);
	return ((int)(sum / len));
}

int	min_pos_a(t_node *a)
{
	int	min;
	int	pos;
	int	i;

	min = INT_MAX;
	pos = 0;
	i = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			pos = i;
		}
		i++;
		a = a->next;
	}
	return (pos);
}
