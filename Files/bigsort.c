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
    sort_node_three(stack_a, stack_b);
    tiny_sort(stack_a);
    while(stacksize(stack_b) > 0)
        pa(stack_b, stack_a);
    get_it_together(stack_a);
    //Debugging
    printf("a: ");
    printstack(stack_a);
    printf("b: ");
    printstack(stack_b);
}
