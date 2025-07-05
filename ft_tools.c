/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:10:01 by lalbe             #+#    #+#             */
/*   Updated: 2025/07/05 12:28:38 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Funcion q nos devuelve el valor absoluto de un numero
int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

//Funcion para printear un error cuando el numero q reciba es menor q 1
void	ft_error(int i)
{
	if (i < 1)
		ft_printf("Error\n");
	exit(1);
}

//Es una funcion constructora que crea un nuevo nodo para el stack
t_stack	*ft_new_stack(int value)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		ft_error(1);
	b->value = value;
	b->next = NULL;
	return (b);
}

//Funcion para añadir un nuevo elemento al principio del stack
void	ft_stack_add_front(t_stack **stack, t_stack *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = *stack;
	*stack = new_node;
}
