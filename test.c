/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luviso-p <luviso-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:23:50 by luviso-p          #+#    #+#             */
/*   Updated: 2025/06/30 11:11:25 by luviso-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack, char *name)
{
	printf("\n=== %s ===\n", name);
	if (!stack)
	{
		printf("Stack vacío\n");
		return ;
	}
	while (stack)
	{
		printf("Value: %d, Index: %d\n", stack->value, stack->index);
		stack = stack->next;
	}
	printf("==========\n");
}

t_stack	*ft_create_test_stack(int values[], int size)
{
	t_stack	*stack;
	t_stack	*new_node;
	t_stack	*last;
	int		i;

	stack = NULL;
	last = NULL;
	i = 0;
	while (i < size)
	{
		new_node = malloc(sizeof(t_stack));
		new_node->value = values[i];
		new_node->index = 0;
		new_node->next = NULL;
		new_node->prev = last;
		if (last)
			last->next = new_node;
		else
			stack = new_node;
		last = new_node;
		i++;
	}
	return (stack);
}

int	main(void)
{
	t_stack	*original;
	t_stack	*copia;
	t_stack	*test_a;
	t_stack	*test_b;
	t_stack	*temp;
	int		test_values[] = {42, 7, 100, 3, 15};
	int		pos;

	printf("=== TESTING PUSH_SWAP UTILITY FUNCTIONS ===\n");
	original = ft_create_test_stack(test_values, 5);
	printf("\n1. PROBANDO FT_COPY_STACK:\n");
	copia = ft_copy_stack(original);
	ft_print_stack(original, "Original");
	ft_print_stack(copia, "Copia");
	printf("\n2. PROBANDO FT_SORT_LIST:\n");
	ft_print_stack(copia, "Antes de ordenar");
	ft_sort_list(&copia);
	ft_print_stack(copia, "Después de ordenar");
	printf("\n3. PROBANDO FT_FIND_INDEX:\n");
	printf("ft_find_index(42): %d\n", ft_find_index(copia, 42));
	printf("ft_find_index(7): %d\n", ft_find_index(copia, 7));
	printf("ft_find_index(100): %d\n", ft_find_index(copia, 100));
	printf("\n4. PROBANDO FT_GET_INDEX:\n");
	ft_print_stack(original, "Antes de ft_get_index");
	ft_get_index(&original);
	ft_print_stack(original, "Después de ft_get_index");
	printf("\n5. PROBANDO FT_STACK_LEN:\n");
	printf("Longitud del stack original: %d\n", ft_stack_len(original));
	printf("Longitud del stack copia: %d\n", ft_stack_len(copia));
	printf("\n6. PROBANDO FT_FIND_INDEX_UP/DOWN:\n");
	printf("ft_find_index_up (rango 1-2): %d\n", ft_find_index_up(&original, 1, 2));
	printf("ft_find_index_down (rango 1-2): %d\n", ft_find_index_down(&original, 1, 2));
	printf("ft_find_index_up (rango 0-4): %d\n", ft_find_index_up(&original, 0, 4));
	printf("ft_find_index_down (rango 0-4): %d\n", ft_find_index_down(&original, 0, 4));
	printf("\n7. PROBANDO FT_ABS:\n");
	printf("ft_abs(-5): %d\n", ft_abs(-5));
	printf("ft_abs(3): %d\n", ft_abs(3));
	printf("ft_abs(0): %d\n", ft_abs(0));
	printf("\n8. PROBANDO FT_GET_COST:\n");
	test_a = ft_create_test_stack((int[]){1, 3, 5}, 3);
	test_b = ft_create_test_stack((int[]){2, 4}, 2);
	temp = test_b;
	pos = 0;
	while (temp)
	{
		temp->pos = pos;
		temp->target = pos + 1;
		temp->a_cost = 0;
		temp->b_cost = 0;
		pos++;
		temp = temp->next;
	}
	printf("Antes de ft_get_cost - Stack B:\n");
	temp = test_b;
	while (temp)
	{
		printf("  Elemento %d: pos=%d, target=%d, a_cost=%d, b_cost=%d\n",
			temp->value, temp->pos, temp->target, temp->a_cost, temp->b_cost);
		temp = temp->next;
	}
	ft_get_cost(&test_a, &test_b);
	printf("Después de ft_get_cost - Stack B:\n");
	temp = test_b;
	while (temp)
	{
		printf("  Elemento %d: pos=%d, target=%d, a_cost=%d, b_cost=%d\n",
			temp->value, temp->pos, temp->target, temp->a_cost, temp->b_cost);
		temp = temp->next;
	}
	ft_free_stack(original);
	ft_free_stack(copia);
	ft_free_stack(test_a);
	ft_free_stack(test_b);
	printf("\n=== TODOS LOS TESTS DE UTILIDADES COMPLETADOS ===\n");
	printf("(Nota: ft_cheap_sort y ft_moves requieren funciones de movimiento aún no implementadas)\n");
	return (0);
}
