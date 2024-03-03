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
    int cost;
    int index;
    int position;

    position = 0;
    index = (stacksize(stack_a)/2) - 1;
    cost = INT_MAX;

    current = *stack_a;
    while(current && position <= stacksize(stack_a)/2)
    {
        current->target = get_target_b(stack_b, current->number);
        cost = get_index(stack_b, current->target);
        current->cost = position + cost;
        current->index = position;
        position++;
        current = current->next;
    }
    
    while(current)
    {
        current->target = get_target_b(stack_b, current->number);
        cost = get_index(stack_b, current->target);
        current->cost = index + cost;
        current->index = position;
        position++;
        index--;
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