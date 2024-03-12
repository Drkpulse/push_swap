/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 11:30:38 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/01 11:30:38 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	thelastsort(t_Node **stack_a, t_Node **stack_b)
{
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	sort_node_three(stack_a, stack_b);
	tiny_sort(stack_a);
	while (stacksize(stack_b) > 0)
		pa(stack_b, stack_a);
	get_it_together(stack_a);
}

void	tiny_sort(t_Node **stack)
{
	while (!stack_sorted(*stack))
	{
		if ((*stack)->number > (*stack)->next->number)
			sa(stack);
		else
			rra(stack);
	}
}

void	sort_node_three(t_Node **stack_a, t_Node **stack_b)
{
	t_Node	*current;

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
