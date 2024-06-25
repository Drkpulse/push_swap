/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 10:05:27 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/13 10:05:27 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

static void	error(t_Node **a, t_Node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 7);
	exit(1);
}

static void	parse_command(t_Node **a, t_Node **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(command, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(command, "sa\n"))
		swapations(a);
	else if (!ft_strcmp(command, "sb\n"))
		swapations(b);
	else if (!ft_strcmp(command, "ss\n"))
		get_both_moving(a, b, 's');
	else if (!ft_strcmp(command, "ra\n"))
		rotations(a);
	else if (!ft_strcmp(command, "rb\n"))
		rotations(b);
	else if (!ft_strcmp(command, "rr\n"))
		get_both_moving(a, b, 'r');
	else if (!ft_strcmp(command, "rra\n"))
		revrotate(a);
	else if (!ft_strcmp(command, "rrb\n"))
		revrotate(b);
	else if (!ft_strcmp(command, "rrr\n"))
		get_both_moving(a, b, 'e');
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_Node		*stack_a;
	t_Node		*stack_b;
	char		*next_line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		catch_error(NULL, NULL, NULL, 2);
	validator(&stack_a, argv, argc);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&stack_a, &stack_b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(stack_a) && stack_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (EXIT_SUCCESS);
}

void	get_both_moving(t_Node **stack_a, t_Node **stack_b, char flag)
{
	if (flag == 's')
	{
		swapations(stack_a);
		swapations(stack_b);
	}
	else if (flag == 'r')
	{
		rotations(stack_a);
		rotations(stack_b);
	}
	else if (flag == 'e')
	{
		revrotate(stack_a);
		revrotate(stack_b);
	}
}
