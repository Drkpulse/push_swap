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
    Node_Stack *head;
    int target;
    target = INT_MIN;

    head = *stack_b;
    while (head)
    {
        if(head->number < number && head->number > target)
            target = head->number;
        head = head->next;
    }
if (target == INT_MIN)
        target = get_biggest(stack_b);
    return (target);
}