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
# include "../Libft/libft.h"
# include "checker.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct Node_Stack
{
	long				number;
	int					index;
	int					cost;
	int					target;
	bool				median;
	struct Node_Stack	*target_node;
	struct Node_Stack	*next;
}	t_Node;

bool		stack_sorted(t_Node *stack);
void		ini_stack(t_Node **stack, char **argv);
void		ini_node(t_Node **stack);
int			validator(t_Node **stack, char **argv, int argc);
bool		duplicates(char **argv);
bool		syntax_error(char *str_nbr);

// Swap Fucntions
void		swapations(t_Node **stack);
void		sa(t_Node **stack);
void		sb(t_Node **stack);
void		ss(t_Node **astack, t_Node **bstack);

// Rotation Functions
void		rotations(t_Node **stack);
void		ra(t_Node **stack);
void		rb(t_Node **stack);
void		rr(t_Node **astack, t_Node **bstack);
void		revrotate(t_Node **stack);
void		rra(t_Node **stack);
void		rrb(t_Node **stack);
void		rrr(t_Node **astack, t_Node **bstack);

// Push Functions
void		push(t_Node **frststack, t_Node **lststack);
void		pa(t_Node **bstack, t_Node **astack);
void		pb(t_Node **astack, t_Node **bstack);

// Sorting Functions
t_Node		*get_node_b(t_Node **stack_b, int number);
t_Node		*get_node_b(t_Node **stack_b, int number);
t_Node		*get_biggest_node(t_Node **stack);
t_Node		*get_lowest_node(t_Node **stack);
int			stacksize(t_Node **stack);
int			catch_cost(t_Node **stack_a);
int			get_more_moves(int index, bool median, int itarget, bool tmedian);
void		tiny_sort(t_Node **stack);
void		thelastsort(t_Node **stack_a, t_Node **stack_b);
void		update_index(t_Node **stack);
void		get_node_push(t_Node **stack, t_Node **target_node,
				char stack_name);
void		get_node_cost(t_Node **stack_a, t_Node **stack_b);
void		sort_node_three(t_Node **stack_a, t_Node **stack_b);
void		get_it_together(t_Node **stack);

// Cleaning Functions
void		free_stack(t_Node **stack);
void		free_argv(char **argv);
void		ft_clean(t_Node **stack_a, t_Node **stack_b, char **argv);
void		catch_error(t_Node **stack_a, t_Node **stack_b, char **argv,
				bool argv_f);

// Printing Functions
void		printstack(t_Node **stack);
void		print_info(t_Node **stack);

#endif
