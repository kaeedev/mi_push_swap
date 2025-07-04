/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chunks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 13:51:53 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/04 14:19:58 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Inicializa la estructura de datos del chunk */
void	ft_init_chunk_data(t_chunk_data *data, int len)
{
    if (len <= 100)
        data->chunk_size = len / 6; // Para 100 números
    else
        data->chunk_size = len / 10; // ✅ Para 500 números (13 chunks de ~38)
    data->pushed_total = 0;
    data->current_max = data->chunk_size;
}

/* Procesa un elemento del chunk actual */
void	ft_process_chunk_element(t_stack **a, t_stack **b, t_chunk_data *data)
{
    pb(a, b, 1);
    if (ft_stack_len(*b) >= 2 
	&& (*b)->index < data->current_max - data->chunk_size / 2)
        rb(b, 1);
    data->pushed_total++;
    if (data->pushed_total >= data->chunk_size)
    {
        data->current_max += data->chunk_size;
        data->pushed_total = 0;
    }
}
/* Procesa elementos por chunks */
void	ft_process_chunk(t_stack **a, t_stack **b, int *i, int chunk)
{
    if ((*a)->index <= *i)
    {
        pb(a, b, 1);
        if ((*b)->index < *i - chunk / 2)
            rb(b, 1);
    }
    else
        ra(a, 1);
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
