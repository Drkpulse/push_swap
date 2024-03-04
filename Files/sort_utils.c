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

int get_target_b(Node_Stack **stack_b, int number)
{
    Node_Stack *top;
    int target;
    target = INT_MIN;

    top = *stack_b;
    while (top)
    {
        if(top->number < number && top->number > target)
            target = top->number;
        top = top->next;
    }
if (target == INT_MIN)
        target = get_biggest(stack_b);
    return (target);
}

int get_target_a(Node_Stack **stack_a, int number)
{
    Node_Stack *top;
    int target;
    target = INT_MAX;

    top = *stack_a;
    while (top)
    {
        if(top->number > number && top->number < target)
            target = top->number;
        top = top->next;
    }
    if (target == INT_MAX)
        target = get_lowest(stack_a);
    return (target);
}

void    get_cost(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;

    current = *stack_a;
    while(current && get_index(stack_a, current->number) <= stacksize(stack_a)/2)
    {
        current->target = get_target_b(stack_b, current->number);
        current->cost = get_moves(get_index(stack_a, current->number), get_index(stack_b, current->target));
        current->index = get_index(stack_a, current->number);
        //printf("Get Cost for Number: %ld, Target: %d with cost %d\n", current->number, current->target, current->cost);
        current = current->next;
        
    }

    while(current)
    {
        current->target = get_target_b(stack_b, current->number);
        current->cost = get_moves(stacksize(stack_a) - 1 - get_index(stack_a, current->number), get_index(stack_b, current->target));
        current->index = get_index(stack_a, current->number);
        //printf("Get Cost for Number: %ld, Target: %d with cost %d\n", current->number, current->target, current->cost);
        current = current->next;
        
    }
    printf("Costs Updated\n");
}

int get_index(Node_Stack **stack, int target)
{
    Node_Stack *top;
    int index;

    index = 0;
    top = *stack;
    while (top)
    {
        if (top->number == target)
            return (index);
        index++;
        top = top->next;
    }
    return (index);
}

int catch_cost(Node_Stack **stack_a)
{
    Node_Stack *current;
    int saved_cost;
    int cheap_index;
    saved_cost = INT_MAX;
    cheap_index = 0;

    current = *stack_a;

    while(current->cost >= 0 && current->next)
        {
            if(current->cost < saved_cost)
            {
                saved_cost = current->cost;
                cheap_index =current->index;
            }
            current = current->next;
        }
    return(cheap_index);
}