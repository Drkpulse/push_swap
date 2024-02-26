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

#include "push_swap.h"

bool    stack_sorted(Node_Stack *stack)
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

void    validator(Node_Stack **stack, char **argv)
{
    int i;

    i = 0;
    while (argv[i])
	{
        if (syntax_error(argv[i]))
        {
            printf("Error Syntax\n");
            exit(1);
        }
        i++;
    }
    if (duplicates(stack, argv))
    {
        printf("Error Duplicates\n");
        exit(1);
    }
    ini_stack(stack, argv);
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

bool    duplicates(Node_Stack **stack, char **argv)
{
    int i = 0;
    while (argv[i]) {
        int j = i + 1;
        while (argv[j]) {
            if (strcmp(argv[i], argv[j]) == 0) {
                return (true);
            }
            j++;
        }
        i++;
    }
}


void    ini_stack(Node_Stack **stack, char **argv)
{
    int i;
    Node_Stack *new;
    Node_Stack *temp;

    i = 0;
    while (argv[i])
    {
        new = (Node_Stack *)malloc(sizeof(Node_Stack));
        if (!new)
        {
            printf("Error malloc\n");
            exit(1);
        }
        new->number = ft_atol(argv[i]);
        new->next = NULL;
        new->previous = NULL;
        if (!*stack)
        {
            *stack = new;
            temp = *stack;
        }
        else
        {
            temp->next = new;
            new->previous = temp;
            temp = new;
        }
        i++;
    }
}