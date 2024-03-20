/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:43 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/18 13:30:26 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	rotations(t_Node **stack)
{
	t_Node	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	last_node = *stack;
	while (last_node->next != NULL)
		last_node = last_node->next;
	last_node->next = *stack;
	*stack = (*stack)->next;
	last_node->next->next = NULL;
	update_index(stack);
}

void	ra(t_Node **stack)
{
	rotations(stack);
	printf("ra\n");
}

void	rb(t_Node **stack)
{
	rotations(stack);
	printf("rb\n");
}

void	rr(t_Node **astack, t_Node **bstack)
{
	rotations(astack);
	rotations(bstack);
	printf("rr\n");
}
