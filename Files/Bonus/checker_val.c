/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:51:40 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/13 20:51:40 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	c_validator(t_cNode **stack, char **argv, int argc)
{
	int	i;
	int	flag;

	flag = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		flag = 0;
	}
	i = flag;
	while (argv[i])
	{
		if (argv[i] == NULL || c_syntax_error(argv[i]))
			c_catch_error(NULL, NULL, argv, !flag);
		i++;
	}
	if (c_duplicates(argv))
		c_catch_error(NULL, NULL, argv, !flag);
	c_ini_stack(stack, argv);
	if (flag == 0)
		free_argv(argv);
	return (flag);
}

bool	c_syntax_error(char *str_nbr)
{
	if (!(*str_nbr == '+'
			|| *str_nbr == '-'
			|| (*str_nbr >= '0' && *str_nbr <= '9')))
		return (true);
	if ((*str_nbr == '+'
			|| *str_nbr == '-')
		&& !(str_nbr[1] >= '0' && str_nbr[1] <= '9'))
		return (true);
	while (*++str_nbr)
	{
		if (!(*str_nbr >= '0' && *str_nbr <= '9'))
			return (true);
	}
	return (false);
}

bool	c_duplicates(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (strcmp(argv[i], argv[j]) == 0)
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	c_ini_stack(t_cNode **stack, char **argv)
{
	int			i;
	t_cNode		*new;
	t_cNode		*temp;

	i = 0;
	while (argv[i])
	{
		new = (t_cNode *)malloc(sizeof(t_cNode));
		if (!new)
			c_catch_error(stack, NULL, argv, 0);
		new->number = ft_atol(argv[i]);
		if (!*stack)
			*stack = new;
		else
		{
			temp = *stack;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		i++;
	}
}

void	c_catch_error(t_cNode **a, t_cNode **b, char **argv, bool argv_f)
{
	write(2, "\033[0;31mKO\033[0m\n", 15);
	if (argv_f)
		free_argv(argv);
	c_free_stack(a);
	c_free_stack(b);
}
