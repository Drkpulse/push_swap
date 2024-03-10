/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inventions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsoeferr < joseferr@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 12:42:58 by jsoeferr          #+#    #+#             */
/*   Updated: 2024/03/10 12:42:58 by jsoeferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_node_three(Node_Stack **stack_a, Node_Stack **stack_b)
{
	Node_Stack	*current;

	if (*stack_a == NULL)
		return ;
	while (stacksize(stack_a))
	{
		current = *stack_a;
		update_index(stack_b);
		update_index(stack_a);
		get_node_cost(stack_a, stack_b);
		while (current->index != catch_cost(stack_a))
			current = current->next;
		if (!current->median && !current->target_node->median)
			while (current->index > 0 && current->target_node->index > 0)
				rr(stack_a, stack_b);
		if (current->median && current->target_node->median)
			while (current->index > 0 && current->target_node->index > 0)
				rrr(stack_a, stack_b);
		get_node_push(stack_a, &current, 'a');
		get_node_push(stack_b, &current->target_node, 'b');
		pb(stack_a, stack_b);
	}
}

void	get_node_cost(Node_Stack **stack_a, Node_Stack **stack_b)
{
	Node_Stack	*current;
	int			size;
	int			tsize;

	current = *stack_a;
	size = stacksize(stack_a);
	tsize = stacksize(stack_b);
	while (current != NULL)
	{
		current->target_node = get_node_b(stack_b, current->number);
		if (current->target_node != NULL)
		{
			current->target = current->target_node->number;
			current->cost = get_more_moves(current->index, current->median, current->target_node->index, current->target_node->median, size, tsize);
		}
		current = current->next;
	}
}

Node_Stack	*get_node_b(Node_Stack **stack_b, int number)
{
	Node_Stack	*top;
	Node_Stack	*target_node;
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

Node_Stack	*get_lowest_node(Node_Stack **stack)
{
	Node_Stack	*current;
	Node_Stack	*lowest_node;
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

Node_Stack	*get_biggest_node(Node_Stack **stack)
{
	Node_Stack	*current;
	Node_Stack	*biggest_node;
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

int	get_more_moves(int index, bool median, int target_index, bool tmedian, int size_a, int size_b)
{
	if (median)
		index = size_a - 1 - index;
	if (tmedian)
		target_index = size_b - 1 - target_index;
	if ((median && tmedian) || (!median && !tmedian))
	{
		if (index > target_index)
			return (index);
		else
			return (target_index);
	}
	else
		return (index + target_index);
}

void	get_node_push(Node_Stack **stack, Node_Stack **target_node, char stack_name)
{
	Node_Stack	*current;
	Node_Stack	*target;

	current = *stack;
	target = *target_node;
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

void	get_it_together(Node_Stack **stack)
{
	Node_Stack	*min;

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
