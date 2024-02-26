/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:21:54 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/26 18:21:54 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void get_biggest(Node_Stack **stack, long *biggest)
{
    Node_Stack *current;

    current = *stack;
    *biggest = current->number;
    while (current)
    {
        if (current->number > *biggest)
            *biggest = current->number;
        current = current->next;
    }
}

void get_lowest(Node_Stack **stack, long *lowest)
{
    Node_Stack *current;

    current = *stack;
    *lowest = current->number;
    while (current)
    {
        if (current->number < *lowest)
            *lowest = current->number;
        current = current->next;
    }
}

void stacksize(Node_Stack **stack, int *size)
{
    Node_Stack *current;

    current = *stack;
    *size = 0;
    while (current)
    {
        *size += 1;
        current = current->next;
    }
}