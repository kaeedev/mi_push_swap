/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 14:07:12 by lalbe             #+#    #+#             */
/*   Updated: 2025/06/29 14:14:04 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Devuelve el indice minimo de los elementos en un stack
int ft_find_min(t_stack **stack)
{
    t_stack *temp;
    int min;

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