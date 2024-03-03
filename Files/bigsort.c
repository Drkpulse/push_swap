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
    get_cost(stack_a, stack_b);
    Node_Stack *print;
    print = *stack_a;
    while(print)
    {
        printf("number: %ld ", print->number);
        printf("index: %d ", print->index);
        printf("target: %d ", print->target);
        printf("cost: %d\n", print->cost);
        print = print->next;
    }

    sort_until_three(stack_a, stack_b);
    //tiny_sort(stack_a);
    //return_to_base(stack_a, stack_b);

    // Debugging
    printf("a: ");
    printstack(stack_a);
    printf("b: ");
    printstack(stack_b);

    // COST & TARGET DEBUG
    print = *stack_b;
    while(print)
    {
        printf("number: %ld ", print->number);
        printf("index: %d ", print->index);
        printf("target: %d ", print->target);
        printf("cost: %d\n", print->cost);
        print = print->next;
    }
}

void sort_until_three(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;
    //Node_Stack *test;
    //int saved_cost;
    int index_b;
    //saved_cost = INT_MAX;

    current = *stack_a;
    //test = *stack_a;

    while (stacksize(stack_a) > 3)
    {
        get_cost(stack_a, stack_b);
        /*
        while(test->cost > 1)
        {
            if(test->cost < saved_cost)
                saved_cost = test->cost;
            test = test->next;
        }
        */
        index_b = get_index(stack_b, current->target);
        if(current->index < stacksize(stack_a)/2)
        {
            // Get both up
            while(current->index > 0 && index_b > 0)
            {
                rr(stack_a, stack_b);
                current->index--;
                index_b--;
            }
            // Only Stack A needs moving
            while(current->index > 0)
            {
                ra(stack_a);
                current->index--;
            }
            // Only Stack B needs Moving
            while(index_b > 0)
            {
                rb(stack_b);
                index_b--;
            }
            // Get it to B
            pb(stack_a, stack_b);
            printf("Moves Done\n");
        }
        if(current->index >= stacksize(stack_a)/2)
        {   
            // Get both up
            while(current->index < stacksize(stack_a) && index_b < stacksize(stack_b))
            {
                rrr(stack_a, stack_b);
                current->index++;
                index_b++;
            }
            // Only stack A up
            while(current->index < stacksize(stack_a))
            {
                rra(stack_a);
                current->index++;
            }
            // Only stack B up
            while(index_b < stacksize(stack_b))
            {
                rrb(stack_b);
                index_b++;
            }
            pb(stack_a, stack_b);
            printf("Moves Done\n");
        }
    }
}

/*
void return_to_base(Node_Stack **stack_a, Node_Stack **stack_b)
{
    Node_Stack *current;

    current = *stack_b;

    while(current)
    {
        
    }
}*/