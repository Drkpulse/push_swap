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

int stacksize(Node_Stack **stack)
{
    Node_Stack *current;
    int size;
    if (!*stack)
        return (0);
    current = *stack;
    size = 0;
    while (current)
    {
        ++size;
        current = current->next;
    }
    return (size);
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

void print_info(Node_Stack **stack)
{
    Node_Stack *print;
    print = *stack;
    if(!print)
        return ;
    while(print)
    {
        printf("number: %ld ", print->number);
        printf("index: %d ", print->index);
        printf("target: %d ", print->target);
        printf("cost: %d\n", print->cost);
        print = print->next;
    }
}