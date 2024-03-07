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
if (*stack == NULL || (*stack)->next == NULL) {
        return;
    }
    Node_Stack* second_last_node = *stack;
    while (second_last_node->next->next != NULL) {
        second_last_node = second_last_node->next;
    }
    Node_Stack* last_node = second_last_node->next;
    second_last_node->next = NULL;
    last_node->next = *stack;
    *stack = last_node;
    update_index(stack);
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