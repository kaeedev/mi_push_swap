/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_index.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lalbe <lalbe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 15:25:13 by lalbe             #+#    #+#             */
/*   Updated: 2025/06/28 15:39:03 by lalbe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *copy_stack(t_stack *src)
{
    t_stack *copy;
    t_stack *last;
    t_stack *temp;

    copy = NULL;
    last = NULL;
    while(src)
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