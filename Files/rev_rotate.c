/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 14:30:56 by marvin            #+#    #+#             */
/*   Updated: 2024/02/25 14:30:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    revrotate(Node_Stack **stack)
{
    long temp;
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
    revrotate(stack);
    printf("rra\n");
}

void    rrb(Node_Stack **stack)
{
    revrotate(stack);
    printf("rrb\n");
}

void    rrr(Node_Stack **astack, Node_Stack **bstack)
{
    revrotate(astack);
    revrotate(bstack);
    printf("rrr\n");
}