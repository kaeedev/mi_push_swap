/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:41:24 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/05 12:11:59 by lalbe            ###   ########.fr       */
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

/* Función principal optimizada */
void	ft_sort_max(t_stack **a, t_stack **b)
{
	t_chunk_data	data;
	int				len;
	int				i;

	len = ft_stack_len(*a);
	ft_init_chunk_data(&data, len);
	i = 0;
	while (ft_stack_len(*a) > 3)
		ft_process_chunk_logic(a, b, &data, &i);
	ft_sort_three(a);
	ft_return_from_b(a, b);
	ft_final_sort(a);
}
