/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortiny.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:16 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/25 21:09:16 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    tiny_sort(Node_Stack **stack)
{
    while(!stack_sorted(*stack))
    {
        if ((*stack)->number > (*stack)->next->number)
            sa(stack);

        else
            rra(stack);
    }
}

void    smallsort(Node_Stack **stack)
{
    while(!stack_sorted(*stack))
    {
        while((*stack)->number > (*stack)->next->number)
        {
            
        }
    }
}