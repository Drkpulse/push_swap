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

#include "../include/checker.h"

void	c_push(t_cNode **frststack, t_cNode **lststack)
{
	t_cNode	*tmp;

	if (*frststack == NULL)
		return ;
	tmp = *frststack;
	*frststack = (*frststack)->next;
	tmp->next = *lststack;
	*lststack = tmp;
}

void	c_pa(t_cNode **bstack, t_cNode **astack)
{
	c_push(bstack, astack);
}

void	c_pb(t_cNode **astack, t_cNode **bstack)
{
	c_push(astack, bstack);
}
