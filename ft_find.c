/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:07:12 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 14:21:41 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/* Devuelve el indice minimo de los elementos en un stack */
int	ft_find_min(t_stack **stack)
{
	t_stack	*temp;
	int		min;

	temp = *stack;
	min = temp->index;
	while (temp)
	{
		if (temp->index < min)
			min = temp->index;
		temp = temp->next;
	}
	return (min);
}

// Devuelve el indice maximo de los elementos en un stack
int	ft_find_max(t_stack **stack)
{
	t_stack	*temp;
	int		max;

	temp = *stack;
	max = temp->index;
	while (temp)
	{
		if (temp->index > max)
			max = temp->index;
		temp = temp->next;
	}
	return (max);
}

//Busca y devuelve la posicion del elemento con el indice min
//en el stack
int	ft_find_pos_min(t_stack **stack, int min)
{
	t_stack	*temp;
	int		pos_min;

	temp = *stack;
	pos_min = 0;
	while (temp)
	{
		if (temp->index == min)
			return (pos_min);
		pos_min ++;
		temp = temp->next;
	}
	return (-1);
}

//Busca y devuelve la posicion del elemento con el indice max
//en el stack
int	ft_find_pos_max(t_stack **stack, int max)
{
	t_stack	*temp;
	int		pos_max;

	temp = *stack;
	pos_max = 0;
	while (temp)
	{
		if (temp->index == max)
			return (pos_max);
		pos_max ++;
		temp = temp->next;
	}
	return (-1);
}

//Devuelve el indice del ultimo elemento del stack
int	ft_find_last(t_stack **stack)
{
	t_stack	*temp;
	
	temp = *stack;
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp->index);
}
