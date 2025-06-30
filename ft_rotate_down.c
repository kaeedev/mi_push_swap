/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_down.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 13:03:57 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 11:07:19 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rra rota el ultimo elemento del stack a y lo pone el primero. 
 * [20, 30, 10]->[10,20,30] */
void	rra(t_stack **a, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if (!*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *a;
	(*a)->prev = last;
	*a = last;
	if (print == 1)
		ft_printf("rra\n");
}

/* rrb rota el ultimo elemento del stack b y lo pone el primero. */
void	rrb(t_stack **b, int print)
{
	t_stack	*last;
	t_stack	*second_last;

	if ((!*b) || !(*b)->next)
		return ;
	last = *b;
	while (last->next)
		last = last->next;
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *b;
	(*b)->prev = last;
	*b = last;
	if (print == 1)
		ft_printf("rrb\n");
}

/* rrr ejecuta simultaneamente rra y rrb. rota las ultimas posiciones de a y b 
 * a las primeras */
void	rrr(t_stack **a, t_stack **b, int print)
{
	rra(a, 0);
	rrb(b, 0);
	if (print == 1)
		ft_printf("rrr\n");
}

/* ahorra movimientos cuando necesitamos rotar ambos elementos hacia abajo 
 * (ultimo elemento va al principio).
 * En lugar de hacer las rotaciones por separado, las hace juntas 
 * para ahorrar movimientos
 * Rota el ultimo elemento a la primera posicion de ambas pilas hasta 
 * que el coste sea 0 */
void	rrr_rot(t_stack **a, t_stack **b, int *a_cost, int *b_cost)
{
	while (*a_cost < 0 && *b_cost < 0)
	{
		rrr(a, b, 1);
		(*a_cost)++;
		(*b_cost)++;
	}
}

/* Ejecuta todas las rotaciones necesarias en el stack b hasta q el coste sea 0
 * si es de coste positivo hará rb (rota el primer elemento al ultimo)
 * Si es de coste negativo hará rrb (rota el ultimo elemento al primero) */
void	b_rot(t_stack **b, int *cost)
{
	while (*cost != 0)
	{
		if (*cost > 0)
		{
			rb(b, 1);
			(*cost)--;
		}
		else if (*cost < 0)
		{
			rrb(b, 1);
			(*cost)++;
		}
	}
}
