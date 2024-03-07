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
   if (*stack == NULL || (*stack)->next == NULL)
        return;
    Node_Stack* last_node = *stack;
    while (last_node->next != NULL) {
        last_node = last_node->next;
    }
    last_node->next = *stack;
    *stack = (*stack)->next;
    last_node->next->next = NULL;
    update_index(stack);
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