/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 10:08:51 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/26 10:08:51 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push(Node_Stack **frststack, Node_Stack **lststack)
{
    Node_Stack  *tmp;

    if (*frststack)
    {
        tmp = *frststack;
        *frststack = (*frststack)->next;
        tmp->next = *lststack;
        *lststack = tmp;
    }
}

void    pa(Node_Stack **bstack, Node_Stack **astack)
{ 
    // DEBUG
    printf("Number: %ld\n", (*bstack)->number);
    push(bstack, astack);
    printf("pa\n");    
}

void    pb(Node_Stack **astack, Node_Stack **bstack)
{
    // DEBUG
    printf("Number: %ld\n", (*astack)->number);
    push(astack, bstack);
    printf("pb\n");
}