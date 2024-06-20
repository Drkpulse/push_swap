/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:20:22 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/01 11:20:22 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	get_node_cost(t_Node **stack_a, t_Node **stack_b)
{
	t_Node		*current;
	int			index;
	int			target_index;

	current = *stack_a;
	while (current != NULL)
	{
		current->target_node = get_node_b(stack_b, current->number);
		if (current->target_node != NULL)
		{
			index = current->index;
			target_index = current->target_node->index;
			if (current->median)
				index = stacksize(stack_a) - 1 - current->index;
			if (current->target_node->median)
				target_index = stacksize(stack_b) - 1
					- current->target_node->index;
			current->target = current->target_node->number;
			current->cost = get_more_moves(index, current->median,
					target_index, current->target_node->median);
		}
		current = current->next;
	}
}
int	catch_cost(t_Node **stack)
{
	t_Node		*current;
	int			saved_cost;
	int			cheap_index;

	current = *stack;
	saved_cost = INT_MAX;
	cheap_index = 0;
	if (current == NULL)
		return (-1);
	while (current != NULL && current->cost >= 0)
	{
		if (current->cost < saved_cost)
		{
			saved_cost = current->cost;
			cheap_index = current->index;
		}
		current = current->next;
	}
	return (cheap_index);
}

int	get_more_moves(int index, bool median, int itarget, bool tmedian)
{
	if (!median && !tmedian)
	{
		if (index > itarget)
			return (index + median);
		else
			return (itarget + tmedian);
	}
	else if (median && tmedian)
	{
		if (index > itarget)
			return (index + median);
		else
			return (itarget + tmedian);
	}
	else
		return (index + median + itarget + tmedian);
}

void	update_index(t_Node **stack)
{
	t_Node		*top;
	int			index;

	if (!stack)
		return ;
	index = 0;
	top = *stack;
	while (top)
	{
		top->index = index;
		if (index > stacksize(stack) / 2)
			top->median = true;
		else
			top->median = false;
		index++;
		top = top->next;
	}
}

void	get_it_together(t_Node **stack)
{
	t_Node	*min;

	if (*stack == NULL || stack_sorted(*stack))
		return ;
	min = get_lowest_node(stack);
	if (min == NULL)
		return ;
	while (!stack_sorted(*stack) && *stack != min)
	{
		if (!min->median)
			ra(stack);
		else
			rra(stack);
	}
}
