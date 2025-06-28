/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:19:04 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/28 15:17:04 by lalbe            ###   ########.fr       */
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
void    ra(t_stack **a, int print);
void    rb(t_stack **b, int print);
void    rr(t_stack **a, t_stack **b, int print);
void    rr_rot(t_stack **a, t_stack **b, int *a_cost, int *b_cost);
void    a_rot(t_stack **a, int *cost);
void    sa(t_stack **a, int print);
void    sb(t_stack **b, int print);
void    ss(t_stack **a, t_stack **b, int print);
#endif