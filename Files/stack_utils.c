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

int get_biggest(Node_Stack **stack)
{
    Node_Stack *current;
    int biggest;

    current = *stack;
    biggest = current->number;
    while (current)
    {
        if (current->number > biggest)
            biggest = current->number;
        current = current->next;
    }
    return (biggest);
}

int get_lowest(Node_Stack **stack)
{   
    Node_Stack *current;
    int lowest;

    current = *stack;
    lowest = current->number;
    while (current)
    {
        if (current->number < lowest)
            lowest = current->number;
        current = current->next;
    }
    return (lowest);
}

void stacksize(Node_Stack **stack)
{
    Node_Stack *current;
    int size;
    current = *stack;
    size = 0;
    while (current)
    {
        size += 1;
        current = current->next;
    }
}

void printstack(Node_Stack **stack)
{
    Node_Stack *current;

    current = *stack;
    while (current)
    {
        printf("%ld ", current->number);
        current = current->next;
    }
    printf("\n");
}