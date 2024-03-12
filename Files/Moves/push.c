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

#include "../push_swap.h"

void	push(t_Node **frststack, t_Node **lststack)
{
	t_Node	*tmp;

	if (*frststack == NULL)
		return ;
	tmp = *frststack;
	*frststack = (*frststack)->next;
	tmp->next = *lststack;
	*lststack = tmp;
	update_index(frststack);
	update_index(lststack);
}

void	pa(t_Node **bstack, t_Node **astack)
{
	push(bstack, astack);
	printf("pa\n");
}

void	pb(t_Node **astack, t_Node **bstack)
{
	push(astack, bstack);
	printf("pb\n");
}
