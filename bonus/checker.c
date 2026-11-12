/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:10:14 by msingh            #+#    #+#             */
/*   Updated: 2026/01/26 13:54:58 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	which_action2(char *str, t_node **a, t_node **b)
{
	if (ft_strncmp(str, "ra\n", 3) == 0)
		rotate(a);
	else if (ft_strncmp(str, "rb\n", 3) == 0)
		rotate(b);
	else if (ft_strncmp(str, "rr\n", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(str, "rra\n", 4) == 0)
		rrotate(a);
	else if (ft_strncmp(str, "rrb\n", 4) == 0)
		rrotate(b);
	else if (ft_strncmp(str, "rrr\n", 4) == 0)
	{
		rrotate(a);
		rrotate(b);
	}
	else
		return (-1);
	return (0);
}

int	which_action(char *str, t_node **a, t_node **b)
{
	int	i;

	i = 0;
	if (ft_strncmp(str, "sa\n", 3) == 0)
		swap(a);
	else if (ft_strncmp(str, "sb\n", 3) == 0)
		swap(b);
	else if (ft_strncmp(str, "ss\n", 3) == 0)
	{
		swap(a);
		swap(b);
	}
	else if (ft_strncmp(str, "pa\n", 3) == 0)
		push(b, a);
	else if (ft_strncmp(str, "pb\n", 3) == 0)
		push(a, b);
	else
		i = which_action2(str, a, b);
	return (i);
}

void	gnl_call(t_node **a, t_node **b, int flag, char **av)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		i = which_action(str, a, b);
		if (i < 0)
		{
			free(str);
			if (flag == 0)
				free_split(av);
			free_stack(a);
			free_stack(b);
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		free(str);
	}
	free(str);
}

int	is_only_spaces(char *s)
{
	int	i;

	if (!s || s[0] == '\0')
		return (1);
	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_node	*a;
	t_node	*b;
	int		i;

	a = 0;
	b = 0;
	i = 1;
	if (ac < 2)
		return (0);
	if (ac == 2 && is_only_spaces(av[1]))
		return (ft_putendl_fd("Error", 2), 1);
	if (ac == 2)
		av = ft_split(av[i--], ' ');
	stack_init(&a, av + i, i);
	gnl_call(&a, &b, i, av);
	if (is_sorted(&a) == 1 && list_len(b) == 0)
		ft_printf("OK");
	else
		ft_printf("KO");
	if (i == 0)
		free_split(av);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
