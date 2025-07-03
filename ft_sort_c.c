/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:39:03 by lalbe             #+#    #+#             */
/*   Updated: 2025/07/03 14:32:30 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Se encarga de encontrar el indice mas alto en la pila
int    ft_high_index(t_stack *stack)
{
    int index;

    index = stack->index;
    while (stack)
    {
        if (stack->index > index)
            index = stack->index;
        stack = stack->next;
    }
    return (index);
}

//Se encarga de encontrar la posicion del elemento con el indice mas bajo del stack
int ft_low_index(t_stack **stack)
{
    t_stack *temp;
    int     low_index;
    int     low_pos;
    int     current_pos;

    temp = *stack;
    low_index = temp->index;
    low_pos = 0;
    current_pos = 0;
    while (temp)
    {
        if (temp->index < low_index)
        {
            low_index = temp->index;
            low_pos = current_pos;
        }
        temp = temp->next;
        current_pos ++;
    }
    return (low_pos);
}

//Se encarga de ordenar la pila de manera que el elemento con el indice mas bajo
//este en la parte superior de la pila
void    ft_sort_min(t_stack **stack)
{
    int max;
    
    if (be_sorted(*stack))
        return ;
    max = ft_high_index(*stack); //indice del elemento mas grande
    if ((*stack)->index == max) //si el elemento mas grande esta en primera posicion...
        ra(stack, 1);
        if ((*stack)->index > (*stack)->next->index) //si queda despues del ra q el primer elemento es mayor al segundo, se swapea
            sa(stack, 1);
    else if ((*stack)->next->index == max) //si esta en segundda
        rra(stack, 1);
        if ((*stack)->index > (*stack)->next->index)
            sa(stack, 1);
    else //si esta en tercera
    {
        if ((*stack)->index > (*stack)->next->index)
            sa(stack, 1);
    }
}

//Se encarga de reordenar el stack A de manera que el elemento con el indice mas bajo
//este en la parte superior del stack
void    shifte_change(t_stack **a)
{
    int low_pos;
    int len_stack;
    int moves;

    low_pos = ft_low_index(*a);
    len_stack = ft_stack_len(*a);
    if (low_pos > (len_stack / 2))
    {
        moves = len_stack - low_pos;
        while (moves > 0)
        {
            rra(a, 1);
            moves --;
        }
    }
    else
    {
        while (low_pos > 0)
        {
            ra(a, 1);
            low_pos --;
        }
    }
}
