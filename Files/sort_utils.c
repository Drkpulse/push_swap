/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:20:22 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/01 11:20:22 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    update_index(Node_Stack **stack)
{
    Node_Stack *top;
    int index;
    if(!stack)
        return;
    index = 0;
    top = *stack;
    while (top)
    {
        top->index = index;
        if(index > stacksize(stack)/2)
            top->median = true;
        else
            top->median = false;
        index++;
        top = top->next;
        
    }
}

int catch_cost(Node_Stack **stack)
{
    Node_Stack *current;
    int saved_cost;
    int cheap_index;

    current = *stack;
    saved_cost = INT_MAX;
    cheap_index = 0;

    if (current == NULL)
        return -1;

    while (current != NULL && current->cost >= 0)
        {
            if(current->cost < saved_cost)
            {
                saved_cost = current->cost;
                cheap_index = current->index;
            }
            current = current->next;
        }
    return(cheap_index);
}