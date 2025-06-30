/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:19:04 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 14:52:03 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include "ft_printf/ft_printf.h"
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				pos;
	int				target;
	int				a_cost;
	int				b_cost;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target_node;
	bool			above;
	bool			best;
}	t_stack;

void	pa(t_stack **a, t_stack **b, int print);
void	pb(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b, int print);
void	rrr_rot(t_stack **a, t_stack **b, int *a_cost, int *b_cost);
void	b_rot(t_stack **b, int *cost);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rr_rot(t_stack **a, t_stack **b, int *a_cost, int *b_cost);
void	a_rot(t_stack **a, int *cost);
void	sa(t_stack **a, int print);
void	sb(t_stack **b, int print);
void	ss(t_stack **a, t_stack **b, int print);
t_stack	*ft_copy_stack(t_stack *src);
void	ft_sort_list(t_stack **list);
int		ft_find_index(t_stack *sorted_list, int value);
void	ft_get_index(t_stack **a);
void	ft_free(t_stack **stack);
void	ft_free_all(t_stack **a, t_stack **b);
int		ft_find_index_up(t_stack **a, int min, int max);
int		ft_find_index_down(t_stack **a, int min, int max);
void	ft_cheap_sort(t_stack **a, t_stack **b);
void	ft_get_cost(t_stack **a, t_stack **b);
int		ft_stack_len(t_stack *stack);
void	ft_moves(t_stack **a, t_stack **b, int a_cost, int b_cost);
int		ft_abs(int a);
int		ft_find_min(t_stack **stack);
int		ft_find_max(t_stack **stack);
int		ft_find_pos_min(t_stack **stack, int min);
int		ft_find_pos_max(t_stack **stack, int max);
int		ft_find_last(t_stack **stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
int		be_sorted(t_stack **a);

void	ft_print_stack(t_stack *stack, char *name);
t_stack	*ft_create_test_stack(int values[], int size);
#endif