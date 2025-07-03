/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 11:10:01 by lalbe             #+#    #+#             */
/*   Updated: 2025/07/03 16:43:00 by lalbe            ###   ########.fr       */
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
t_stack *ft_new_stack(int value)
{
	t_stack	*b;

	b = (t_stack *)malloc(sizeof(t_stack));
	if (!b)
		ft_error(1);
	b->value = value;
	b->next = NULL;
	return (b);
}

//Se encarga de devolver el numero de numeros negativos en un stack
int	ft_count_neg(t_stack **stack)
{
	int		count;
	t_stack *temp;

	temp = *stack;
	count = 0;
	while (temp)
	{
		if (temp->value < 0)
			count ++;
		temp = temp->next;
	}
	return (count);
}

//Se encarga de mover todos los elementos del stack B al stack A
void	ft_b_to_a(t_stack **a, t_stack **b)
{
	while(*b)
		pa(a, b, 1);
}
