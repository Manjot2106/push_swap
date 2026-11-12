/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:09:15 by msingh            #+#    #+#             */
/*   Updated: 2026/01/28 09:15:22 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node(t_node **stack, int nbr, char **av, int split)
{
	t_node	*node;
	t_node	*last_node;

	node = malloc(sizeof(t_node));
	if (!node)
		free_error(stack, av, split);
	node->next = NULL;
	node->value = nbr;
	if (!(*stack))
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = ft_find_last(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

void	stack_init(t_node **stack, char **av, int split)
{
	int	nbr;
	int	i;

	i = 0;
	if (!av[i])
		free_error(stack, av, split);
	while (av[i])
	{
		if (!parse_int(av[i]))
			free_error(stack, av, split);
		nbr = ft_atoi(av[i]);
		if (!not_duplicate(*stack, nbr))
			free_error(stack, av, split);
		add_node(stack, nbr, av, split);
		i++;
	}
}
