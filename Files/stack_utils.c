/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 18:21:54 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/26 18:21:54 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	stacksize(t_Node **stack)
{
	t_Node		*current;
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

bool	stack_sorted(t_Node *stack)
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

void	printstack(t_Node **stack)
{
	t_Node	*current;

	current = *stack;
	while (current)
	{
		printf("%ld ", current->number);
		current = current->next;
	}
	printf("\n");
}

void	print_info(t_Node **stack)
{
	t_Node	*print;

	print = *stack;
	if (!print)
		return ;
	while (print)
	{
		printf("number: %ld ", print->number);
		printf("index: %d ", print->index);
		printf("target: %d ", print->target);
		printf("cost: %d\n", print->cost);
		print = print->next;
	}
}

bool	number_validator(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] >= '0' && argv[1][i] <= '9')
			return (true);
		i++;
	}
	return (false);
}
