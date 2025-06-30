/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:18:36 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 11:07:28 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sa intercambia los dos primeros elementos del stack a
 * [A, B, C, D]->[B, A, C, D] */
void	sa(t_stack **a, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*a) || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	*a = second;
	second->prev = NULL;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	if (print == 1)
		ft_printf("sa\n");
}

/* sb intercambia los dos primeros elementos del stack b */
void	sb(t_stack **b, int print)
{
	t_stack	*first;
	t_stack	*second;

	if (!(*b) || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	(*b) = second;
	second->prev = NULL;
	first->next = second->next;
	first->prev = second;
	if (second->next)
		second->next->prev = first;
	second->next = first;
	if (print == 1)
		ft_printf("sb\n");
}

/* ss ejecuta simultaneamente sa y sb. intercambia las primeras posiciones 
 * de a y b */
void	ss(t_stack **a, t_stack **b, int print)
{
	sa(a, 0);
	sb(b, 0);
	if (print == 1)
		ft_printf("ss\n");
}
