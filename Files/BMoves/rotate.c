/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:43 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/25 21:09:43 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	c_rotations(t_cNode **stack)
{
	t_cNode	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
}

void	c_ra(t_cNode **stack)
{
	c_rotations(stack);
}

void	c_rb(t_cNode **stack)
{
	c_rotations(stack);
}

void	c_rr(t_cNode **astack, t_cNode **bstack)
{
	c_rotations(astack);
	c_rotations(bstack);
}
