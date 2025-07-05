/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:41:24 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/05 11:01:28 by lalbe            ###   ########.fr       */
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

//Devuelve la posicion del elemento minimo en el stack A
/*int	ft_pos_min(t_stack **a, int start_pos)
{
	int		min_pos;
	int		current_pos;
	t_stack	*temp;
	int		min;

	if (!a || !*a)
		return (-1);
	temp = *a;
	min = temp->value;
	min_pos = start_pos;
	current_pos = start_pos;
	while (temp)
	{
		if (temp->value < min)
		{
			min = temp->value;
			min_pos = current_pos;
		}
		temp = temp->next;
		current_pos++;
	}
	return (min_pos);
}*/

//Se encarga de ordenar el stack A y B utilizando diferentes algoritmos de
//orenamiento dependiendo de la posicion de los elementos en el stack A
/*void	ft_sort_end(t_stack **a, t_stack **b)
{
	ft_sort_min(a);
	while (*b)
	{
		ft_find_pos_target(a, b);
		ft_get_cost(a, b);
		ft_cheap_sort(a, b);
		if (!be_sorted(a))
			shifte_change(a);
	}
}*/

/* Procesa un elemento del chunk */
/*void	ft_process_element(t_stack **a, t_stack **b, int *pushed_total)
{
    pb(a, b, 1);
    (*pushed_total)++;
}*/

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

