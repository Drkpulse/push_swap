/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:36 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/25 21:09:36 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	c_revrotate(t_cNode **stack)
{
	t_cNode	*second_last_node;
	t_cNode	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last_node = *stack;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
}

void	c_rra(t_cNode **stack)
{
	c_revrotate(stack);
}

void	c_rrb(t_cNode **stack)
{
	c_revrotate(stack);
}

void	c_rrr(t_cNode **astack, t_cNode **bstack)
{
	c_revrotate(astack);
	c_revrotate(bstack);
}
