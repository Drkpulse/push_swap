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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "./Libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

typedef struct Node_Stack{
    long number;
    struct Node_Stack* next;
    struct Node_Stack* previous;
} Node_Stack;


bool    stack_sorted(Node_Stack *stack);
void    ini_stack(Node_Stack **stack, char **argv);
void    validator(Node_Stack **stack, char **argv);
bool    duplicates(Node_Stack **stack, char **argv);
bool	syntax_error(char *str_nbr);

// Swap Fucntions
void    swapations(Node_Stack **stack);
void    sa(Node_Stack **stack);
void    sb(Node_Stack **stack);
void    ss(Node_Stack **astack, Node_Stack **bstack);

// Rotation Functions
void    rotations(Node_Stack **stack);
void ra(Node_Stack **stack);
void rb(Node_Stack **stack);
void rr(Node_Stack **astack, Node_Stack **bstack);
void revrotate(Node_Stack **stack);
void    rra(Node_Stack **stack);
void    rrb(Node_Stack **stack);
void    rrr(Node_Stack **astack, Node_Stack **bstack);

// Sorting Functions
void    tiny_sort(Node_Stack **stack);
#endif
