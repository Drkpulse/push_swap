/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:44:55 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/04 16:44:55 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_abs(int nbr)
{
    if(nbr < 0)
        nbr = nbr * -1;
    return(nbr);
}

int get_moves(int index, int target_index)
{
    if(index > target_index)
        return(index);
    else
        return(target_index);
}

void    get_return_cost(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;

    current = *stack_b;
    update_index(stack_a);
    update_index(stack_b);
    while(current && current->index <= stacksize(stack_a)/2)
    {
        current->target = get_target_a(stack_a, current->number);
        current->cost = get_moves(current->index, get_index(stack_a, current->target));
        current = current->next;
        
    }

    while(current)
    {
        current->target = get_target_a(stack_a, current->number);
        current->cost = get_moves(stacksize(stack_b) - 1 - current->index, get_index(stack_a, current->target));
        current = current->next;
        
    }
    printf("Costs to Back Updated\n");
}