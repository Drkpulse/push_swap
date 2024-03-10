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
# include <limits.h>

typedef struct Node_Stack{
    long number;
    int index;
    int cost;
    int target;
    bool median;
    struct Node_Stack* target_node;
    struct Node_Stack* next;
    struct Node_Stack* previous;
} Node_Stack;


bool    stack_sorted(Node_Stack *stack);
void    ini_stack(Node_Stack **stack, char **argv);
void    validator(Node_Stack **stack, char **argv);
bool    duplicates(char **argv);
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

// Push Functions
void    push(Node_Stack **frststack, Node_Stack **lststack);
void    pa(Node_Stack **bstack, Node_Stack **astack);
void    pb(Node_Stack **astack, Node_Stack **bstack);

// Sorting Functions
void    tiny_sort(Node_Stack **stack);
void    thelastsort(Node_Stack **stack_a, Node_Stack **stack_b);


int stacksize(Node_Stack **stack);

void update_index(Node_Stack **stack);


int catch_cost(Node_Stack **stack_a);

void    get_return_cost(Node_Stack **stack_a, Node_Stack **stack_b);

void get_push(Node_Stack **stack, int Number, bool median, char stack_name);

// Cleaning Functions
void   free_stack(Node_Stack **stack);
void	free_argv(char **argv);
void ft_clean(Node_Stack **stack, char **argv, bool argv_f);

// Printing Functions
void printstack(Node_Stack **stack);
void print_info(Node_Stack **stack);

// Numbers Funtions


// Testing Functions
Node_Stack* get_node_b(Node_Stack **stack_b, int number);
Node_Stack* get_node_a(Node_Stack **stack_b, int number);
void get_node_push(Node_Stack **stack, Node_Stack **target_node, char stack_name);
int get_more_moves(int index, bool median, int target_index, bool tmedian);
void    get_node_cost(Node_Stack **stack_a, Node_Stack **stack_b);
void sort_node_three(Node_Stack **stack_a, Node_Stack **stack_b);
Node_Stack* get_biggest_node(Node_Stack **stack);

Node_Stack* get_lowest_node(Node_Stack **stack);

void get_it_together(Node_Stack **stack);



#endif
