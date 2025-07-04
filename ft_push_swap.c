/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 14:41:01 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/04 12:34:12 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Esta funcion verifica si el stack A esta ya ordenada en orden
//ascendente
int	be_sorted(t_stack **a)
{
	t_stack	*temp;

	if (a == NULL || *a == NULL)
		return (1);
	temp = *a;
	while (temp && temp->next != NULL)
	{
		if (temp->value < temp->next->value)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}

//Funcion para verificar si hay elementos duplicados en el stack A. Si
//encuentra un duplicado, llama a ft_error
void	ft_be_duplicated(t_stack *a)
{
	t_stack	*temp;

	if (a == NULL)
		ft_error(0);
	while (a && a->next != NULL)
	{
		temp = a->next;
		while (temp)
		{
			if (a->value == temp->value)
				ft_error(0);
			temp = temp->next;
		}
		a = a->next;
	}
}

//Funcion que verifica si una cadena de caracteres corresponde a un numero
//entero valido. Si no, llama a ft_error
int	be_nbr(char *str)
{
	long	nbr;
	int		neg;

	if (!str || !*str)
		ft_error(0);
	neg = 1;
	nbr = 0;
	if (*str == '-')
		neg = -1;
	if (*str == '-' || *str == '+')
		str ++;
	if (!*str)
		ft_error(0);
	while (*str >= '0' && *str <= '9')
	{
		nbr = nbr * 10 + *str - '0';
		str ++;
	}
	if (*str != '\0')
		ft_error(0);
	nbr *= neg;
	if ((nbr < INT_MIN) || (nbr > INT_MAX))
		ft_error(0);
	return ((int)nbr);
}

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;
	t_stack	*temp;
	int		i;
	int		value;

	a = NULL;
	b = NULL;
	temp = NULL;
	if (argc < 2)
		return (0);
	i = argc - 1;
	while (i > 0)
	{
		value = be_nbr(argv[i]);
		temp = ft_new_stack(value);
		temp->next = a;
		a = temp;
		i --;
	}
	ft_be_duplicated(a);
	if (be_sorted(&a))
		return (0);
	ft_sort(&a, &b);
	ft_free_all(&a, &b);
	return (0);
}
