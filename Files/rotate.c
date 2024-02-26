/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:43 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/25 21:09:43 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotations(Node_Stack **stack)
{
    long temp;
    Node_Stack *current;
    if (*stack && (*stack)->next)
    {
        current = *stack;

        temp = current->number;

        while (current->next)
        {
            current->number = current->next->number;
            current = current->next;
        }

        current->number = temp;
    }
}

void ra(Node_Stack **stack)
{
    rotations(stack);
    printf("ra\n");
}

void rb(Node_Stack **stack)
{
    rotations(stack);
    printf("rb\n");
}

void rr(Node_Stack **astack, Node_Stack **bstack)
{
    rotations(astack);
    rotations(bstack);
    printf("rr\n");
}