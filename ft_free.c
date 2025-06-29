/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:16:24 by lalbe             #+#    #+#             */
/*   Updated: 2025/06/29 12:39:02 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Recorre todos los nodos de un stack y libera la memoria de cada nodo
void    ft_free_stack(t_stack *stack)
{
    t_stack *temp;

    while (stack)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}