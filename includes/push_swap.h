/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msingh <msingh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 11:09:58 by msingh            #+#    #+#             */
/*   Updated: 2026/01/31 12:49:49 by msingh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef enum e_move
{
	MOVE_RARB,
	MOVE_RRARRB,
	MOVE_RARRB,
	MOVE_RRARB
}					t_move;

typedef struct s_tab
{
	int				val;
	int				pos_b;
	int				target_pos_a;
}					t_tab;

typedef struct s_lens
{
	int				a;
	int				b;
}					t_lens;

typedef struct s_rot
{
	int				ra;
	int				rb;
	int				rra;
	int				rrb;
}					t_rot;

typedef struct s_best
{
	int				cost;
	int				idx;
	t_move			move;
}					t_best;

void				free_stack(t_node **stack);
void				free_split(char **str);
void				free_error(t_node **stack, char **av, int split);

void				ft_sort_three(t_node **stack_a);
int					is_sorted(t_node **stack_a);
int					ft_find_index(t_node *stack_a, int nbr);

int					parse_int(char *str);
int					check_syntax(char *str, int *sign);
int					not_duplicate(t_node *stack, int nbr);

void				push(t_node **src_stack, t_node **dst_stack);
void				pa(t_node **src_stack, t_node **dst_stack);
void				pb(t_node **src_stack, t_node **dst_stack);

void				rotate(t_node **stack);
void				ra(t_node **stack_a);
void				rb(t_node **stack_b);
void				rr(t_node **stack_a, t_node **stack_b);

void				rrotate(t_node **stack);
void				rra(t_node **stack_a);
void				rrb(t_node **stack_b);
void				rrr(t_node **stack_a, t_node **stack_b);

void				add_node(t_node **stack, int nbr, char **av, int split);
void				stack_init(t_node **stack, char **av, int split);

void				swap(t_node **stack);
void				sa(t_node **stack_a);
void				sb(t_node **stack_b);
void				ss(t_node **stack_a, t_node **stack_b);

t_node				*ft_find_last(t_node *stack);
int					ft_max(t_node *stack);
int					ft_min(t_node *stack);
int					list_len(t_node *stack);

int					which_action2(char *str, t_node **a, t_node **b);
int					which_action(char *str, t_node **a, t_node **b);
void				gnl_call(t_node **a, t_node **b, int flag, char **av);

char				**get_args(int ac, char **av, int *start);

int					max_int(int a, int b);
int					dist_down(int pos, int len);
t_lens				get_lens(t_node *a, t_node *b);
int					calc_mean(t_node *a);
int					min_pos_a(t_node *a);

void				stack_to_array_b(t_node *b, t_tab *tab);
int					target_pos_in_a(t_node *a, int b_val, int min_pos);
void				assign_targets_a(t_node *a, t_tab *tab, int len_b);
void				compute_array_costs(t_tab *c, t_lens lens,
						int costs[4]);

void				scan_costs(int costs[4], int idx, t_best *best);
t_best				pick_best_array_move(t_tab *tab, t_lens lens);

void				do_ra(t_node **a, int *n);
void				do_rb(t_node **b, int *n);
void				do_rra(t_node **a, int *n);
void				do_rrb(t_node **b, int *n);
void				run_rr(t_node **a, t_node **b, t_rot *rot);

void				run_rrr(t_node **a, t_node **b, t_rot *rot);
t_rot				init_rot(t_tab *c, t_lens lens);
void				exec_move_mix(t_node **a, t_node **b, t_rot *rot,
						t_move move);
void				exec_array_choice(t_node **a, t_node **b, t_tab *c,
						t_move move);
void				rotate_to_min(t_node **a, int min, int pos, int len);

void				push_sort_b(t_node **a, t_node **b);
void				push_sort_a(t_node **a, t_node **b);
void				sort_b(t_node **stack_a, t_node **stack_b);
void				finish_rotate(t_node **a);
void				ft_sort(t_node **stack_a, t_node **stack_b);

#endif
