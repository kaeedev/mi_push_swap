/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:51:53 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/05 12:19:31 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Inicializa la estructura de datos del chunk */
void	ft_init_chunk_data(t_chunk_data *data, int len)
{
	if (len <= 100)
		data->chunk_size = len / 4;// Para 100 números
	else
		data->chunk_size = len / 10;// ✅ Para 500 números (13 chunks de ~38)
	data->pushed_total = 0;
	data->current_max = data->chunk_size;
}

void	ft_process_chunk_logic(t_stack **a, t_stack **b, t_chunk_data *data,
	int *i)
{
	if ((*a)->index <= data->current_max)
	{
		pb(a, b, 1);
		if ((*b)->index < (data->current_max - data->chunk_size / 2))
			rb(b, 1);
		(*i)++;
	}
	else
		ra(a, 1);
	if (*i >= data->chunk_size)
	{
		data->current_max += data->chunk_size;
		*i = 0;
	}
}

/* Devuelve todos los elementos de B a A usando el algoritmo de coste mínimo */
void	ft_return_from_b(t_stack **a, t_stack **b)
{
	// Mientras queden elementos en B por mover
	while (*b)
	{
		// 1. Actualizar la información de posición y coste para el estado actual
		ft_find_pos_target(a, b);
		ft_get_cost(a, b);
		// 2. Encontrar y ejecutar el movimiento más barato
		ft_cheap_sort(a, b);
	}
	ft_final_sort(a);
}
