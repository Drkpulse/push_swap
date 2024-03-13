/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:43:41 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/13 20:43:41 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	c_stacksize(t_cNode **stack)
{
	t_cNode		*current;
	int			size;

	if (!*stack)
		return (0);
	current = *stack;
	size = 0;
	while (current)
	{
		++size;
		current = current->next;
	}
	return (size);
}

bool	c_stack_sorted(t_cNode *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->number > stack->next->number)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	c_free_stack(t_cNode **stack)
{
	t_cNode	*current;
	t_cNode	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
