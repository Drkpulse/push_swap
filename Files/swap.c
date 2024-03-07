/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:26:12 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/21 15:26:12 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swapations(Node_Stack **stack)
{
    long temp;
    if (*stack && (*stack)->next)
    {
        temp = (*stack)->number;
        (*stack)->number = (*stack)->next->number;
        (*stack)->next->number = temp;
    }
}

void sa(Node_Stack **stack)
{
    swapations(stack);
    update_index(stack);
    printf("sa\n");
}

void sb(Node_Stack **stack)
{
    swapations(stack);
    update_index(stack);
    printf("sb\n");
}

void ss(Node_Stack **astack, Node_Stack **bstack)
{
    swapations(astack);
    swapations(bstack);
    update_index(astack);
    update_index(bstack);
    printf("ss\n"); 
}