/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:13 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 11:07:56 by luviso-p         ###   ########.fr       */
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

void	ft_get_index(t_stack **a)
{
	t_stack	*sorted_copy;
	t_stack	*original;

	sorted_copy = ft_copy_stack(*a);
	ft_sort_list(&sorted_copy);
	original = *a;
	while (original)
	{
		original->index = ft_find_index(sorted_copy, original->value);
		original = original->next;
	}
	ft_free_stack(sorted_copy);
}
