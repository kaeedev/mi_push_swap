/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:25:02 by lalbe             #+#    #+#             */
/*   Updated: 2025/06/28 14:07:36 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Esta funcion rota el primer elemento del stack a y lo pone el ultimo
//[20, 30, 10]->[30, 10, 20]
void    ra(t_stack **a, int print)
{
    t_stack *temp;
    t_stack *last;
    
    if(!(*a) || !(*a)->next)
        return ;
    temp = *a;
    *a = (*a)->next;
    (*a)->prev = NULL;
    last = *a;
    while(last->next)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
    if (print == 1)
        ft_printf("ra\n");
}

//Rota el primer elemento del stack b y lo pone el ultimo
void    rb(t_stack **b, int print)
{
    t_stack *temp;
    t_stack *last;
    
    if(!(*b) || !(*b)->next)
        return ;
    temp = *b;
    *b = (*b)->next;
    (*b)->prev = NULL;
    last = *b;
    while(last->next)
        last = last->next;
    last->next = temp;
    temp->prev = last;
    temp->next = NULL;
    if (print == 1)
        ft_printf("rb\n");
}

//rr ejecuta simultaneamente ra y rb. rota las primeras posiciones de a y b
// a las ultimas posiciones
void    rr(t_stack **a, t_stack **b, int print)
{
    ra(a, 0);
    rb(b, 0);
    if (print == 1)
        ft_printf("rr\n");
}

// ahorra movimientos cuando necesitamos rotar ambos elementos hacia arriba 
//(primer elemento va el ultimo).
// En lugar de hacer las rotaciones por separado, las hace juntas 
//para ahorrar movimientos
// Rota el el primer elemento a la ultima posicion de ambas pilas hasta 
//que el coste sea 0
void    rr_rot(t_stack **a, t_stack **b, int *a_cost, int *b_cost)
{
    while(*a_cost > 0 && *b_cost > 0)
    {
        rr(a, b, 1);
        (*a_cost)--;
        (*b_cost)--;
    }
}

//Ejecuta todas las rotaciones necesarias en el stack a hasta q el coste sea 0
//si es de coste positivo hará ra (rota el primer elemento al ultimo)
//Si es de coste negativo hará rra (rota el ultimo elemento al primero)
void    a_rot(t_stack **a, int *cost)
{
    while (*cost != 0)
    {
        if (*cost > 0)
        {
            ra(a, 1);
            (*cost)--;
        }
        else if (*cost < 0)
        {
            rra(a, 1);
            (*cost)++;
        }
    }
}