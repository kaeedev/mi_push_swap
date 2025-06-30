/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:41:01 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 14:51:30 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Esta funcion verifica si el stack A esta ya ordenada en orden
//ascendente
int	be_sorted(t_stack **a)
{
	t_stack	*temp;

	if (a == NULL)
		return (1);
	temp = *a;
	while (temp-> != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else 
			return (0);
	}
	return (1);
}