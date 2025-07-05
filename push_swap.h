/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:19:04 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/05 12:49:49 by lalbe            ###   ########.fr       */
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
}	t_stack;

typedef struct s_chunk_data
{
	int	chunk_size;
	int	pushed_total;
	int	current_max;
}	t_chunk_data;

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
void	ft_error(int i);
void	ft_cheap_sort(t_stack **a, t_stack **b);
void	ft_get_cost(t_stack **a, t_stack **b);
int		ft_stack_len(t_stack *stack);
void	ft_moves(t_stack **a, t_stack **b, int a_cost, int b_cost);
int		ft_abs(int n);
int		ft_find_min(t_stack **stack);
int		ft_find_pos_min(t_stack **stack, int min);
void	ft_find_pos_target(t_stack **a, t_stack **b);
int		ft_find_last(t_stack **stack);
int		ft_target(t_stack **a, int index, int target, int pos);
void	ft_add_pos(t_stack **a, t_stack **b);
int		be_sorted(t_stack **a);
void	ft_sort_max(t_stack **a, t_stack **b);
t_stack	*ft_new_stack(int value);
int		be_nbr(char *str);
void	ft_be_duplicated(t_stack *a);
int		ft_atoi(const char *str);
void	ft_sort_three(t_stack **stack);
void	ft_sort_four(t_stack **a, t_stack **b);
void	ft_sort_five(t_stack **a, t_stack **b);
void	ft_sort(t_stack **a, t_stack **b);
void	ft_return_from_b(t_stack **a, t_stack **b);
void	ft_init_chunk_data(t_chunk_data *data, int len);
void	ft_final_sort(t_stack **a);
void	ft_stack_add_front(t_stack **stack, t_stack *new_node);
void	ft_process_chunk_logic(t_stack **a, t_stack **b, t_chunk_data *data,
			int *i);
#endif