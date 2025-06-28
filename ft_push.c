/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 11:34:42 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/28 12:46:55 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//pa toma el primer elemento del stack b y lo mueve al primero del stack a
void	pa(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	temp->next = *a;
	temp->prev = NULL;
	if (*a)
		(*a)->prev = temp;
	*a = temp;
	if (print == 1)
		ft_printf("pa\n");		
}

//pb toma el primer elemento del stack a y lo mueve al primero del stack b
void	pb(t_stack **a, t_stack **b, int print)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	temp->next = *b;
	temp->prev = NULL;
	if (*b)
		(*b)->prev = temp;
	*b = temp;
	if (print == 1)
		ft_printf("pb\n");
}