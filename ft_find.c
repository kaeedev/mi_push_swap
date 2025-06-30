/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:07:12 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 11:04:28 by luviso-p         ###   ########.fr       */
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