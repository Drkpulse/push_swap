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


static int	ft_strcmp(char *str_1, char *str_2)
{
	while (*str_1 == *str_2
		&& *str_1)
	{
		++str_1;
		++str_2;
	}
	return (*str_1 - *str_2);
}

static void	error(t_cNode **a, t_cNode **b)
{
	c_free_stack(a);
	c_free_stack(b);
	write(2, "\033[0;31mError\033[0m\n", 17);
	exit(1);
}

static void	parse_command(t_cNode **a, t_cNode **b, char *command)
{
	if (!ft_strcmp(command, "pa\n"))
		c_pa(a, b);
	else if (!ft_strcmp(command, "pb\n"))
		c_pb(b, a);
	else if (!ft_strcmp(command, "sa\n"))
		c_sa(a);
	else if (!ft_strcmp(command, "sb\n"))
		c_sb(b);
	else if (!ft_strcmp(command, "ss\n"))
		c_ss(a, b);
	else if (!ft_strcmp(command, "ra\n"))
		c_ra(a);
	else if (!ft_strcmp(command, "rb\n"))
		c_rb(b);
	else if (!ft_strcmp(command, "rr\n"))
		c_rr(a, b);
	else if (!ft_strcmp(command, "rra\n"))
		c_rra(a);
	else if (!ft_strcmp(command, "rrb\n"))
		c_rrb(b);
	else if (!ft_strcmp(command, "rrr\n"))
		c_rrr(a, b);
	else
		error(a, b);
}

int	main(int argc, char **argv)
{
	t_cNode		*stack_a;
	t_cNode		*stack_b;
	int			len;
	char		*next_line;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	c_validator(&stack_a, argv, argc);
	len = c_stacksize(&stack_a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&stack_a, &stack_b, next_line);
		free(next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (c_stack_sorted(stack_a) && c_stacksize(&stack_a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	c_free_stack(&stack_a);
	c_free_stack(&stack_b);
	return (0);
}
