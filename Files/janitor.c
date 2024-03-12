/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   janitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:09:26 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/25 21:09:26 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_Node **stack)
{
	t_Node	*current;
	t_Node	*next;

	current = *stack;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

void	free_argv(char **arr)
{
	int	i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	ft_clean(t_Node **a, t_Node **b, char **argv)
{
	argv = NULL;
	if (argv)
		free_argv(argv);
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
	exit(0);
}

void	catch_error(t_Node **a, t_Node **b, char **argv, bool argv_f)
{
	write(2, "\033[0;31mError\033[0m\n", 17);
	if (argv_f)
		free_argv(argv);
	ft_clean(a, b, argv);
}
