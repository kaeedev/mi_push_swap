/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:13 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/04 12:43:04 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Crea una copia exacta del stack original conectando los nodos uno tras otro
t_stack	*ft_copy_stack(t_stack *src)
{
	t_stack	*copy;
	t_stack	*last;
	t_stack	*temp;

	copy = NULL;
	last = NULL;
	while (src)
	{
		temp = malloc(sizeof(t_stack));
		if (!temp)
		{
			ft_free(&copy);
			return (NULL);
		}
		temp->value = src->value;
		temp->next = NULL;
		if (last)
			last->next = temp;
		else
			copy = temp;
		last = temp;
		src = src->next;
	}
	return (copy);
}

/* Ordena una lista de menor a mayor intercambiando valores */
void	ft_sort_list(t_stack **list)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		swap_value;

	if (!*list || !(*list)->next)
		return ;
	temp = *list;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->value > temp2->value)
			{
				swap_value = temp->value;
				temp->value = temp2->value;
				temp2->value = swap_value;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

/* Busca un valor en la lista ordenada y devuelve su posicion (indice) */
int	ft_find_index(t_stack *sorted_list, int value)
{
	int	index;

	index = 0;
	while (sorted_list)
	{
		if (sorted_list->value == value)
			return (index);
		index++;
		sorted_list = sorted_list->next;
	}
	return (-1);
}

//Convierte los valores de los elementos en indices relativos que representan
//su posicion en el orden ascendente
//Stack original: [42, 7, 100, 3, 15]
//42 → index = 2 (es el 3° más pequeño)
//7 → index = 1 (es el 2° más pequeño)
//100 → index = 4 (es el más grande)
//3 → index = 0 (es el más pequeño)
//15 → index = 3 (es el 4° más pequeño)
//Resultado: [42(2), 7(1), 100(4), 3(0), 15(3)]
void	ft_get_index(t_stack **a)
{
	t_stack	*sorted_copy;
	t_stack	*original;

	sorted_copy = ft_copy_stack(*a);
	if (!sorted_copy)
	{
		ft_error(0);
		return ;
	}
	ft_sort_list(&sorted_copy);
	original = *a;
	while (original)
	{
		original->index = ft_find_index(sorted_copy, original->value);
		original = original->next;
	}
	ft_free(&sorted_copy);
}
