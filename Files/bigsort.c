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
    int i;
    pb(stack_a, stack_b);
    pb(stack_a, stack_b);
    i = get_target_b(stack_b, 5);
    printstack(stack_a);
    printstack(stack_b);

}

void sort_for_three(Node_Stack **stack_a, Node_Stack **stack_b)
{
    while (stacksize(stack_a) > 3)
    {
        if (get_target_b(stack_b, (*stack_a)->number) == (*stack_b)->number)
            pb(stack_a, stack_b);
        else
            rrb(stack_b);
    }
    
}