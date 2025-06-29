/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 11:23:50 by lalbe             #+#    #+#             */
/*   Updated: 2025/06/29 14:02:26 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_print_stack(t_stack *stack, char *name)
{
    printf("\n=== %s ===\n", name);
    if (!stack)
    {
        printf("Stack vacío\n");
        return;
    }
    
    while (stack)
    {
        printf("Value: %d, Index: %d\n", stack->value, stack->index);
        stack = stack->next;
    }
    printf("==========\n");
}

t_stack *ft_create_test_stack(int values[], int size)
{
    t_stack *stack = NULL;
    t_stack *new_node;
    t_stack *last = NULL;
    
    for (int i = 0; i < size; i++)
    {
        new_node = malloc(sizeof(t_stack));
        new_node->value = values[i];
        new_node->index = 0; // Inicializar
        new_node->next = NULL;
        new_node->prev = last;
        
        if (last)
            last->next = new_node;
        else
            stack = new_node;
            
        last = new_node;
    }
    return stack;
}

int main()
{
    printf("=== TESTING PUSH_SWAP UTILITY FUNCTIONS ===\n");
    
    // Datos de prueba
    int test_values[] = {42, 7, 100, 3, 15};
    t_stack *original = ft_create_test_stack(test_values, 5);
    
    // 1. Probar ft_copy_stack
    printf("\n1. PROBANDO FT_COPY_STACK:\n");
    t_stack *copia = ft_copy_stack(original);
    ft_print_stack(original, "Original");
    ft_print_stack(copia, "Copia");
    
    // 2. Probar ft_sort_list
    printf("\n2. PROBANDO FT_SORT_LIST:\n");
    ft_print_stack(copia, "Antes de ordenar");
    ft_sort_list(&copia);
    ft_print_stack(copia, "Después de ordenar");
    
    // 3. Probar ft_find_index
    printf("\n3. PROBANDO FT_FIND_INDEX:\n");
    printf("ft_find_index(42): %d\n", ft_find_index(copia, 42));
    printf("ft_find_index(7): %d\n", ft_find_index(copia, 7));
    printf("ft_find_index(100): %d\n", ft_find_index(copia, 100));
    
    // 4. Probar ft_get_index
    printf("\n4. PROBANDO FT_GET_INDEX:\n");
    ft_print_stack(original, "Antes de ft_get_index");
    ft_get_index(&original);
    ft_print_stack(original, "Después de ft_get_index");
    
    // 5. Probar ft_stack_len
    printf("\n5. PROBANDO FT_STACK_LEN:\n");
    printf("Longitud del stack original: %d\n", ft_stack_len(original));
    printf("Longitud del stack copia: %d\n", ft_stack_len(copia));
    
    // 6. Probar ft_find_index_up y ft_find_index_down
    printf("\n6. PROBANDO FT_FIND_INDEX_UP/DOWN:\n");
    printf("ft_find_index_up (rango 1-2): %d\n", ft_find_index_up(&original, 1, 2));
    printf("ft_find_index_down (rango 1-2): %d\n", ft_find_index_down(&original, 1, 2));
    printf("ft_find_index_up (rango 0-4): %d\n", ft_find_index_up(&original, 0, 4));
    printf("ft_find_index_down (rango 0-4): %d\n", ft_find_index_down(&original, 0, 4));
    
    // 7. Probar ft_abs
    printf("\n7. PROBANDO FT_ABS:\n");
    printf("ft_abs(-5): %d\n", ft_abs(-5));
    printf("ft_abs(3): %d\n", ft_abs(3));
    printf("ft_abs(0): %d\n", ft_abs(0));
    
    // 8. Test básico de ft_get_cost (sin dependencias de movimiento)
    printf("\n8. PROBANDO FT_GET_COST:\n");
    t_stack *test_a = ft_create_test_stack((int[]){1, 3, 5}, 3);
    t_stack *test_b = ft_create_test_stack((int[]){2, 4}, 2);
    
    // Simular posiciones y targets para test
    t_stack *temp = test_b;
    int pos = 0;
    while (temp)
    {
        temp->pos = pos;
        temp->target = pos + 1; // Target simulado
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
    
    // Limpiar memoria
    ft_free_stack(original);
    ft_free_stack(copia);
    ft_free_stack(test_a);
    ft_free_stack(test_b);
    
    printf("\n=== TODOS LOS TESTS DE UTILIDADES COMPLETADOS ===\n");
    printf("(Nota: ft_cheap_sort y ft_moves requieren funciones de movimiento aún no implementadas)\n");
    return 0;
}