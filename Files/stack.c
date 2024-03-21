/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:58:25 by joseferr          #+#    #+#             */
/*   Updated: 2024/01/24 17:11:38 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	validator(t_Node **stack, char **argv, int argc)
{
	int	i;
	int	flag;

	flag = 1;
	if (argc == 2 && number_validator(argv))
	{
		argv = ft_split(argv[1], ' ');
		flag = 0;
	}
	i = flag;
	while (argv[i])
	{
		if (argv[i] == NULL || syntax_error(argv[i]))
			catch_error(NULL, NULL, argv, !flag);
		i++;
	}
	if (duplicates(argv, flag))
		catch_error(NULL, NULL, argv, !flag);
	ini_stack(stack, argv, flag);
	if (flag == 0)
		free_argv(argv);
	return (flag);
}

bool	syntax_error(char *str_nbr)
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

bool	duplicates(char **argv, int flag)
{
	int	i;
	int	j;

	i = flag;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atol(argv[i]) == ft_atol(argv[j]))
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

void	ini_stack(t_Node **stack, char **argv, int flag)
{
	int			i;
	t_Node		*new;
	t_Node		*temp;

	i = flag;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > 2147483647 || ft_atol(argv[i]) < -2147483648)
			catch_error(stack, NULL, argv, !flag);
		new = (t_Node *)malloc(sizeof(t_Node));
		if (!new)
			catch_error(stack, NULL, argv, !flag);
		new->number = ft_atol(argv[i]);
		ini_node(&new);
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

void	ini_node(t_Node **stack)
{
	t_Node	*temp;

	temp = *stack;
	temp->next = NULL;
	temp->target_node = NULL;
	temp->cost = 0;
	temp->target = 0;
	temp->index = 1;
	temp->median = false;
}
