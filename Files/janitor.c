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

#include "../push_swap.h"

void   free_stack(Node_Stack **stack)
{
    Node_Stack *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

int ft_clean(Node_Stack **stack, bool argv_f)
{
    if(argv_f)
        free_argv(argv);
    free_stack(stack);
    printf("Error\n");
    return (1);
}
    
