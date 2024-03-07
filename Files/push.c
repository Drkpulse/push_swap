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
    if (*frststack == NULL)
        return;

    tmp = *frststack;
    *frststack = (*frststack)->next;
    tmp->next = *lststack;
    *lststack = tmp;

    update_index(frststack);
    update_index(lststack);
}

void    pa(Node_Stack **bstack, Node_Stack **astack)
{ 
    push(bstack, astack);
    printf("pa\n");    
}

void    pb(Node_Stack **astack, Node_Stack **bstack)
{
    push(astack, bstack);
    printf("pb\n");
}