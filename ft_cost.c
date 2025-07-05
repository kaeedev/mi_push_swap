/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:55:38 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/05 11:44:43 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Encuentra el elemento del stack B que es mas barato de mover al stack A
 * y ejecuta ese movimiento. Se llama repetidamente hasta vaciar B */
void	ft_cheap_sort(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	int		cheap;
	int		a_cost;
	int		b_cost;
	int		current_cost;

	temp = *b;
	cheap = INT_MAX;
	while (temp)
	{
		current_cost = ft_abs(temp->a_cost) + ft_abs(temp->b_cost);
		if (current_cost < cheap)
		{
			cheap = current_cost;
			a_cost = temp->a_cost;
			b_cost = temp->b_cost;
		}
		temp = temp->next;
	}
	ft_moves(a, b, a_cost, b_cost);
}

/* Calcula el costo de cada elemento en el stack a y b para ser movido
 * al stack A */
void	ft_get_cost(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;
	int		len_a;
	int		len_b;

	temp_b = *b;
	len_a = ft_stack_len(*a);
	len_b = ft_stack_len(*b);
	while (temp_b)
	{
		temp_b->b_cost = temp_b->pos;
		if (temp_b->pos > len_b / 2)
			temp_b->b_cost = (len_b - temp_b->pos) * -1;
		temp_b->a_cost = temp_b->target;
		if (temp_b->target > len_a / 2)
			temp_b->a_cost = (len_a - temp_b->target) * -1;
		temp_b = temp_b->next;
	}
}
