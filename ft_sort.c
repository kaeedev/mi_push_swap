/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 12:32:48 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/05 12:12:58 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Cuenta el numero de elementos en un stack. Nos dice el tamaño de un stack */
int	ft_stack_len(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}

//Esta funcion se encarga de ordenar una pila de 3 elementos
//utilizando operaciones de rotacion y swap
void	ft_sort_three(t_stack **stack)
{
	int	first;
	int	second;
	int	third;

	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if ((first > second) && (first < third))
		sa(stack, 1);
	else if ((first > second) && (first > third) && (second > third))
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if ((first > second) && (first > third) && (second < third))
		ra(stack, 1);
	else if ((first < second) && (first < third))
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if ((first < second) && (first > third))
		rra(stack, 1);
}

//Esta funcion se encarga de ordenar una pila de 4 elementos
//Necesitaremos un stack B para poder ordenar eficientemente
//Mandamos el primer elemento al stack B y luego ordenamos el stack A
//con el algoritmo de 3 elementos. Luego pusheamos de B a A el elemento
//que falta
void	ft_sort_four(t_stack **a, t_stack **b)
{
	int	min;

	min = ft_find_pos_min(a, ft_find_min(a));
	if (min < 2)
	{
		while (ft_find_min(a) != (*a)->index)
			ra(a, 1);
	}
	else
	{
		while (ft_find_min(a) != (*a)->index)
			rra(a, 1);
	}
	pb(a, b, 1);
	if (be_sorted(a) == 1)
		pa(a, b, 1);
	else
	{
		ft_sort_three(a);
		pa(a, b, 1);
	}
}

//Esta funcion se encarga de ordenar una pila de 5 elementos
//Necesitaremos un stack B para poder ordenar eficientemente
//Mandamos los dos primeros elemento al stack B y luego ordenamos el stack A
//con el algoritmo de 3 elementos. Luego pusheamos de B a A los elementos
//que faltan
void	ft_sort_five(t_stack **a, t_stack **b)
{
	int	min1;
	int	min2;

	min1 = ft_find_min(a);
	while ((*a)->index != min1)
	{
		if (ft_find_pos_min(a, min1) < 3)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
	min2 = ft_find_min(a);
	while ((*a)->index != min2)
	{
		if (ft_find_pos_min(a, min2) < 2)
			ra(a, 1);
		else
			rra(a, 1);
	}
	pb(a, b, 1);
	ft_sort_three(a);
	pa(a, b, 1);
	pa(a, b, 1);
}

//Se encarga de ordenar el stack A utilizando diferentes
//algoritmos de ordenamiento dependiendo de la longitud
//de la pila
void	ft_sort(t_stack **a, t_stack **b)
{
	int	stack_len;

	if (!(*a))
		return ;
	stack_len = ft_stack_len(*a);
	ft_get_index(a);
	ft_add_pos(a, b);
	ft_find_pos_target(a, b);
	if (be_sorted(a))
		return ;
	if (stack_len < 2)
		ft_error(0);
	else if (stack_len == 2)
		sa(a, 1);
	else if (stack_len == 3)
		ft_sort_three(a);
	else if (stack_len == 4)
		ft_sort_four(a, b);
	else if (stack_len == 5)
		ft_sort_five(a, b);
	else if (stack_len > 5)
		ft_sort_max(a, b);
}
