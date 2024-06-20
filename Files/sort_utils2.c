/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:44:55 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/04 16:44:55 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_Node	*get_node_b(t_Node **stack_b, int number)
{
	t_Node		*top;
	t_Node		*target_node;
	int			target;

	target = INT_MIN;
	target_node = NULL;
	top = *stack_b;
	while (top)
	{
		if (top->number < number && top->number > target)
		{
			target_node = top;
			target = top->number;
		}
		top = top->next;
	}
	if (target_node == NULL)
		target_node = get_biggest_node(stack_b);
	return (target_node);
}

t_Node	*get_lowest_node(t_Node **stack)
{
	t_Node		*current;
	t_Node		*lowest_node;
	int			lowest;

	lowest = INT_MAX;
	lowest_node = NULL;
	current = *stack;
	while (current)
	{
		if (current->number < lowest)
		{
			lowest = current->number;
			lowest_node = current;
		}
		current = current->next;
	}
	return (lowest_node);
}

t_Node	*get_biggest_node(t_Node **stack)
{
	t_Node		*current;
	t_Node		*biggest_node;
	int			biggest;

	biggest = INT_MIN;
	biggest_node = NULL;
	current = *stack;
	while (current)
	{
		if (current->number > biggest)
		{
			biggest = current->number;
			biggest_node = current;
		}
		current = current->next;
	}
	return (biggest_node);
}

void	get_node_push(t_Node **stack, t_Node **ttarget, char stack_name)
{
	t_Node	*current;
	t_Node	*target;

	current = *stack;
	target = *ttarget;
	while (current != target)
	{
		if (stack_name == 'a')
		{
			if (!target->median)
				ra(stack);
			else
				rra(stack);
		}
		if (stack_name == 'b')
		{
			if (!target->median)
				rb(stack);
			else
				rrb(stack);
		}
		current = *stack;
	}
}
