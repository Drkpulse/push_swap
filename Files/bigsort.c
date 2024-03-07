/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:30:38 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/01 11:30:38 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void thelastsort(Node_Stack **stack_a, Node_Stack **stack_b)
{
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    sort_until_three(stack_a, stack_b);
    //tiny_sort(stack_a);
    return_to_base(stack_a, stack_b);
    //Debugging
    printf("a: ");
    printstack(stack_a);
    printf("b: ");
    printstack(stack_b);
    
    
}

void sort_until_three(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;
    Node_Stack *target;

    while (stacksize(stack_a))
    {
        current = *stack_a;
        target = *stack_b;

        update_index(stack_b);
        update_index(stack_a);
        get_cost(stack_a, stack_b);

        while(current->index != catch_cost(stack_a))
            current=current->next;
        while(target->number != current->target)
            target=target->next;

        //printf("Number: %ld, CMedian: %d, CIndex: %d, Target: %d, TMedian: %d, TIndex: %d, BHead:%ld, Cost: %d,  \n", current->number, current->median, current->index, current->target, target->median, target->index, target->number, current->cost);
        if(!current->median && !target->median)
        {
           while(current->index > 0 && target->index > 0)
            {
                //printf("I'm here CIndex: %d,TIndex: %d,CNumber: %ld,TNumber: %ld,CTarget: %d\n", current->index, target->index, current->number, target->number, current->target);
                rr(stack_a, stack_b);
            }
        }
        if(current->median && target->median)
        {
            while(current->index > 0 && target->index > 0)
            {
                //printf("I'm here CIndex: %d,TIndex: %d,CNumber: %ld,TNumber: %ld,CTarget: %d\n", current->index, target->index, current->number, target->number, current->target);
                rrr(stack_a, stack_b);
            }
        }
        //print_info(stack_a);
        //print_info(stack_b);
        get_push(stack_a, current->number, current->median, 'a');
        get_push(stack_b, current->target, target->median, 'b');
        pb(stack_a, stack_b);
    }
}


void return_to_base(Node_Stack **stack_a, Node_Stack **stack_b)
{
    int min;
    while(stacksize(stack_b) > 0)
    {
        pa(stack_b, stack_a);
    }
        
    min = get_lowest(stack_a);
    
    while(!stack_sorted(*stack_a))
    {
        if(get_index(stack_a, min) > stacksize(stack_a)/2)
            rra(stack_a);
        else
            ra(stack_a);
    }
    
    
}