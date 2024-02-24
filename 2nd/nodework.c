/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodework.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 16:39:19 by joseferr          #+#    #+#             */
/*   Updated: 2024/01/24 17:11:38 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

stack_node	*find_last_node(stack_node *head)
{
	if (head == NULL)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

void	append_node(stack_node **stack, int nbr)
{
	stack_node	*node;
	stack_node	*last_node;

	if (stack == NULL)
		return ;
	node = malloc(sizeof(stack_node));
	if (node === NULL)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (*stack == NULL)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}
