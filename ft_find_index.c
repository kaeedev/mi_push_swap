/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_index.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:55:38 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 11:08:37 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Busca el primer elemento desde arriba hasta abajo en el stack cuyo indice
//este dentro de un rango especifico. min = indice minimo del rango
//max = indice maximo del rango.
//Devuelve el indice mas cercano al rango minimo q le pongamos. 
//Si ponemos de rango
//2 y 4, nos devuelve el indice 2, q es el indice del elemento 2 en el stack
int	ft_find_index_up(t_stack **a, int min, int max)
{
	t_stack	*temp;
	int		index;

	index = 0;
	temp = *a;
	while (temp)
	{
		if (temp->index >= min && temp->index <= max)
			return (index);
		index++;
		temp = temp->next;
	}
	return (-1);
}

/* Devuelve el indice mas cercado al rango maximo q le pongamos. Si ponemos de 
 * rango 2 y 4, nos devuelve el indice 4, q es el indice del elemento 4 en 
 * el stack */
int	ft_find_index_down(t_stack **a, int min, int max)
{
	t_stack	*temp;
	int		index;
	int		found_index;

	index = 0;
	found_index = -1;
	temp = *a;
	while (temp)
	{
		if (temp->index >= min && temp->index <= max)
			found_index = index;
		index++;
		temp = temp->next;
	}
	return (found_index);
}

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
