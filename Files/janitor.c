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

void free_stack(Node_Stack **stack) {
    Node_Stack *current;
    Node_Stack *next;

    current = *stack;

    while (current) {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

void free_argv(char **argv) {
    int i;

    i = 0;

    if (NULL == argv || NULL == *argv)
        return;
    while (argv[i]) {
        free(argv[i]);
        i++;
    }
    free(argv);
}


void ft_clean(Node_Stack **stack, char **argv, bool argv_f)
{
    if(argv_f)
        free_argv(argv);
    if(stack)
        free_stack(stack);
    printf("Error\n");
    exit(0);
}
