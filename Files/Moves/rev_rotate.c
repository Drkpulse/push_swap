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

#include "../push_swap.h"

void	revrotate(t_Node **stack)
{
	t_Node	*second_last_node;
	t_Node	*last_node;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	second_last_node = *stack;
	while (second_last_node->next->next != NULL)
		second_last_node = second_last_node->next;
	last_node = second_last_node->next;
	second_last_node->next = NULL;
	last_node->next = *stack;
	*stack = last_node;
	update_index(stack);
}

void	rra(t_Node **stack)
{
	revrotate(stack);
	printf("rra\n");
}

void	rrb(t_Node **stack)
{
	revrotate(stack);
	printf("rrb\n");
}

void	rrr(t_Node **astack, t_Node **bstack)
{
	revrotate(astack);
	revrotate(bstack);
	printf("rrr\n");
}
