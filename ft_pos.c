/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:03:52 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/02 14:41:53 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Se encarga de asignar una posicion a cada elemento en ambas pilas
void	ft_add_pos(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		pos_a;
	int		pos_b;

	temp_a = *a;
	pos_a = 0;
	while (temp_a)
	{
		temp_a->pos = pos_a;
		pos_a++;
		temp_a = temp_a->next;
	}
	if (b && *b)
	{
		temp_b = *b;
		pos_b = 0;
		while (temp_b)
		{
			temp_b->pos = pos_b;
			pos_b++;
			temp_b = temp_b->next;
		}
	}
}

//Se encarga de encontrar la posicion objetivo para el elemento en el stack B
// en el stack A
int	ft_target(t_stack **a, int index, int target, int pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index > index && temp_a->index < target )
		{
			target = temp_a->index;
			pos = temp_a->pos;
		}
		temp_a->next;
	}
	if (target != INT_MAX)
		return (pos);
	temp_a = *a;
	while (temp_a)
	{
		if (temp_a->index < target)
		{
			target = temp_a->index;
			pos = temp_a->pos;
		}
		temp_a = temp_a->next;
	}
	return (pos);
}

//Se encarga de encontrar la posicion objetivo para cada elemento en 
//el stack B en el stack A
void	ft_find_pos_target(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;

	temp_b = *b;
	ft_add_pos(a, b);
	while (temp_b)
	{
		ft_target() // por hacer
	}
}