/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 13:03:52 by luviso-p          #+#    #+#             */
/*   Updated: 2025/07/04 14:17:41 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Se encarga de asignar una posicion a cada elemento en ambas pilas
void	ft_add_pos(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		pos_a;
	int		pos_b;

	temp_a = *a;
	pos_a = 0;
	while (temp_a)
	{
		temp_a->pos = pos_a;
		pos_a++;
		temp_a = temp_a->next;
	}
	if (b && *b)
	{
		temp_b = *b;
		pos_b = 0;
		while (temp_b)
		{
			temp_b->pos = pos_b;
			pos_b++;
			temp_b = temp_b->next;
		}
	}
}

//Encuentra la posición correcta donde insertar un elemento del stack B 
//en el stack A para mantener el orden.
//La variable target funciona como "mejor candidato actual". Es como un mrcador que dice
//"este es el mejor lugar hasta ahora para insertar el elemento"
/*
Stack A: [10, 30, 50, 70]  →  índices: [0, 1, 3, 4]
                ↑
         (10=menor, 30=segundo, 50=cuarto, 70=quinto)

Stack B: [40]  →  índice: [2]
          ↑
    (40 sería el tercer elemento en orden: 10, 30, 40, 50, 70)
Elemento B tiene índice = 2
¿Dónde va el elemento B en el stack A?
Stack A actual: [índice 0, índice 1, índice 3, índice 4]
                    ↑                    ↑
                   10                   50

El índice 2 debe ir ENTRE índice 1 y índice 3
Es decir, entre el valor 30 y el valor 50

ITERACIÓN 1: temp_a apunta a elemento con índice 0
- 0 > 2? NO → No actualiza target
- target sigue siendo INT_MAX

ITERACIÓN 2: temp_a apunta a elemento con índice 1  
- 1 > 2? NO → No actualiza target
- target sigue siendo INT_MAX

ITERACIÓN 3: temp_a apunta a elemento con índice 2
- 2 > 2? NO → No actualiza target
- target sigue siendo INT_MAX

ITERACIÓN 4: temp_a apunta a elemento con índice 3
- 3 > 2? SÍ
- 3 < INT_MAX? SÍ → ¡PRIMERA ACTUALIZACIÓN!
- target = 3, pos = posición del elemento con índice 3
- Ahora target = 3 es nuestro "mejor candidato actual"*/
int	ft_target(t_stack **a, int index, int target, int pos)
{
	t_stack	*temp_a;

	temp_a = *a;
	// FASE 1: Buscar el "sucesor más cercano"
	while (temp_a)
	{
		// ¿Es este elemento mayor que el que queremos insertar Y menor que el mejor candidato actual?
		if (temp_a->index > index && temp_a->index < target)
		{
			target = temp_a->index;  // Actualizar el mejor candidato
			pos = temp_a->pos;       // Guardar su posición
		}
		temp_a = temp_a->next;
	}
	// Si encontramos un sucesor válido, devolver su posición
	if (target != INT_MAX)
		return (pos);
	// FASE 2: Si no hay sucesor, buscar el elemento mínimo
	temp_a = *a;  // Volver a empezar desde el inicio del stack A
	while (temp_a)
	{
		// ¿Es este elemento menor que el mejor candidato actual?
		if (temp_a->index < target)
		{
			target = temp_a->index;  // Actualizar al mínimo encontrado
			pos = temp_a->pos;       // Guardar su posición
		}
		temp_a = temp_a->next;
	}
	return (pos);  // Devolver la posición del mínimo
}

/* Rota A hasta que el elemento con índice 0 esté en la cima */
void	ft_final_sort(t_stack **a)
{
    int	min_pos;

    min_pos = ft_find_pos_min(a, 0); 
    if (min_pos <= ft_stack_len(*a) / 2)
    {
        while (min_pos-- > 0)
            ra(a, 1);
    }
    else
    {
        while (min_pos++ < ft_stack_len(*a))
            rra(a, 1);
    }
}

//Se encarga de encontrar la posicion objetivo para cada elemento en 
//el stack B en el stack A
void	ft_find_pos_target(t_stack **a, t_stack **b)
{
	t_stack	*temp_b;

	temp_b = *b;
	ft_add_pos(a, b);
	while (temp_b)
	{
		temp_b->target = ft_target(a, temp_b->index, INT_MAX, 0);
		temp_b = temp_b->next;
	}
}

