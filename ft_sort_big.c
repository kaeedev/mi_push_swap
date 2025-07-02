/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:41:24 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/02 12:46:18 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Mueve un elemento específico del stack B al stack A de la manera más 
 * eficiente posible, minimizando el número total de operaciones. */
void	ft_moves(t_stack **a, t_stack **b, int a_cost, int b_cost)
{
	if (a_cost < 0 && b_cost < 0)
		rrr_rot(a, b, &a_cost, &b_cost);
	else if (a_cost > 0 && b_cost > 0)
		rr_rot(a, b, &a_cost, &b_cost);
	a_rot(a, &a_cost);
	b_rot(b, &b_cost);
	pa(a, b, 1);
}