/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 14:18:36 by lalbe             #+#    #+#             */
/*   Updated: 2025/06/28 15:12:16 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//sa intercambia los dos primeros elementos del stack a
//[A, B, C, D]->[B, A, C, D]
void    sa(t_stack **a, int print)
{
    t_stack *first;
    t_stack *second;
    
    if (!(*a) || !(*a)->next)
        return ;
    first = *a; //primera elemento del stack (A)
    second = (*a)->next; //segunda elemento del stack (B)
    *a = second; //decimos q B es el nuevo primer elemento
    second->prev = NULL; // B ahora no tiene a nadie antes q el porque ahora es primero
    first->next = second->next; //A ahora apunta a quien estaba despues de B (C)
    first->prev = second; //ahora el anterior de A es B
    if (second->next) //si hay mas elementos (C, D, E...)
        second->next->prev = first; //C dice que A esta antes q el
    second->next = first; //B dice q A esta despues de el
    if (print == 1)
        ft_printf("sa\n");    
}

//sb intercambia los dos primeros elementos del stack b
void    sb(t_stack **b, int print)
{
    t_stack *first;
    t_stack *second;

    if (!(*b) || !(*b)->next)
        return ;
    first = *b;
    second = (*b)->next;
    (*b) = second;
    second->prev = NULL;
    first->next = second->next;
    first->prev = second;
    if (second->next)
        second->next->prev = first;
    second->next = first;
    if (print == 1)
        ft_printf("sb\n");
}

//ss ejecuta simultaneamente sa y sb. intercambia las primeras posiciones de a y b
void    ss(t_stack **a, t_stack **b, int print)
{
    sa(a, 0);
    sb(b, 0);
    if (print == 1)
        ft_printf("ss\n");
}