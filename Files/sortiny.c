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

void get_push(Node_Stack **stack, int Number, bool median, char stack_name)
{
    Node_Stack *current;
    int debug = 0;
    current = *stack;
    
    while(current->number != Number)
    {
        //printf("debug: %d, %ld, %d\n", current->index, current->number, Number);
        if(stack_name == 'a')
        {
            if(!median)
                ra(stack);
            else
                rra(stack);
        }
        if(stack_name == 'b')
        {   
            if(!median)
                rb(stack);
            else
                rrb(stack);
         }
         debug++;
         current = *stack;
         //if(debug > 10)
           // exit(0);
    }
}