/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:36 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/25 21:09:36 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    revrotate(Node_Stack **stack)
{
    Node_Stack *current;
    Node_Stack *last;

    if (*stack && (*stack)->next)
    {
        current = *stack;
        last = NULL;

        while (current->next)
        {
            last = current;
            current = current->next;
        }

        last->next = NULL;
        current->next = *stack;
        *stack = current;
    }
}

void    rra(Node_Stack **stack)
{
    // DEBUG
    printf("Number: %ld\n", (*stack)->number);
    revrotate(stack);
    printf("rra\n");
}

void    rrb(Node_Stack **stack)
{
    // DEBUG
    printf("Number: %ld\n", (*stack)->number);
    revrotate(stack);
    printf("rrb\n");
}

void    rrr(Node_Stack **astack, Node_Stack **bstack)
{
    // DEBUG
    printf("Number: %ld\n", (*astack)->number);
    // DEBUG
    printf("Number: %ld\n", (*bstack)->number);
    revrotate(astack);
    revrotate(bstack);
    printf("rrr\n");
}