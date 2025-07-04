/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 14:38:50 by lalbe             #+#    #+#             */
/*   Updated: 2025/07/04 14:32:24 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//La funcion se encarga de mover el elemento en la posicion pos en el stack A
//hacia arriba o hacia abajo dependiendo del valor de i
/*void	ft_move_a(t_stack **a, t_stack **b, int pos, int i)
{
	if (i == 1)
	{
		while (pos++ < ft_stack_len(*a))
		{
			if (*b)
			{
				if ((*b)->index < ft_find_last(&(*b))
					&& (*a)->index > ft_find_last(&(*a)))
					rrr(a, b, 1);
				else
					rra(a, 1);
			}
			else
				rra(a, 1);
		}
	}
	else if (i == 0)
		while (pos-- >= 1)
			ra(a, 1);
}

//Se encarga de seleccionar el elemento mas cercano al centro del stack A y 
//moverlo hacia arriba o hacia abajo dependiendo de su posicion
void    ft_select_a(t_stack **a, t_stack **b)
{
    int len;
    int center_pos;

    len = ft_stack_len(*a);
    center_pos = len / 2;
    if (center_pos <= len / 2)
        ft_move_a(a, b, center_pos, 0);
    else
        ft_move_a(a, b, center_pos, 1);
}*/
