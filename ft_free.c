/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:16:24 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/04 12:38:11 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Recorre todos los nodos de un stack y libera la memoria de cada nodo */
void	ft_free(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	while (*stack)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
	*stack = NULL;
}

//Libera la memoria de ambos stacks a la vez
void	ft_free_all(t_stack **a, t_stack **b)
{
	ft_free(a);
	ft_free(b);
}
