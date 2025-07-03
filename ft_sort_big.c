/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:41:24 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/03 14:32:57 by lalbe            ###   ########.fr       */
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
int	ft_pos_min(t_stack **a, int start_pos)
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
}

//Se encarga de ordenar el stack A y B utilizando diferentes algoritmos de
//orenamiento dependiendo de la posicion de los elementos en el stack A
void	ft_sort_end(t_stack **a, t_stack **b)
{
	ft_sort_min(a); 
	while (*b)
	{
		ft_find_pos_target(a, b);
		ft_get_cost(a, b);
		ft_cheap_sort(a, b);
		if (!be_sorted(*a))
			shifte_change(a);
	}
}
//Se encarga de mover los elementos mas grandes del stack A a la B
//Se utiliza cando hay que ordenar mas de 5 elementos
void	ft_sort_max(t_stack **a, t_stack **b)
{
	int	pos_max;

	pos_max = (ft_stack_len(*a) / 2);
	while (ft_stack_len(*a) >= pos_max + 1)
	{
		if ((*a)->index > pos_max + 1)
			ra(a, 1);
		else
			pb(a, b, 1);
	}
	while (ft_stack_len(*a) >= 1)
		pb(a, b, 1);
	ft_sort_end(a, b);
}