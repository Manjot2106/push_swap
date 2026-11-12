/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:10:02 by msingh            #+#    #+#             */
/*   Updated: 2026/01/26 14:33:34 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**get_args(int ac, char **av, int *start)
{
	if (ac == 2)
	{
		*start = 0;
		return (ft_split(av[1], ' '));
	}
	*start = 1;
	return (av);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	char	**args;
	int		start;

	a = 0;
	b = 0;
	if (ac < 2)
		return (0);
	args = get_args(ac, av, &start);
	if (!args)
		return (1);
	stack_init(&a, args + start, start);
	if (!is_sorted(&a) && list_len(a) <= 3)
		ft_sort_three(&a);
	else if (!is_sorted(&a))
		ft_sort(&a, &b);
	if (ac == 2)
		free_split(args);
	free_stack(&a);
	return (0);
}
