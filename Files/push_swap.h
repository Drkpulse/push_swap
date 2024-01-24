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
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				stack_node;


//*** Commands ***
void			sa(stack_node **a, bool checker);
void			sb(stack_node **b, bool checker);
void			ss(stack_node **a, stack_node **b, bool checker);
void			ra(stack_node **a, bool checker);
void			rb(stack_node **b, bool checker);
void			rr(stack_node **a, stack_node **b, bool checker);
void			rra(stack_node **a, bool checker);
void			rrb(stack_node **b, bool checker);
void			rrr(stack_node **a, stack_node **b, bool checker);
void			pa(stack_node **a, stack_node **b, bool checker);
void			pb(stack_node **b, stack_node **a, bool checker);

//*** Handle input ./push_swap "1 -42 1337" ***
char			**ft_split(char *str, char separator);

//*** Handle errors-free ***
void			free_matrix(char **argv);
void			error_free(stack_node **a, char **argv, bool flag_argc_2);
void			free_stack(stack_node **stack);
int				repetition_error(stack_node *a, int nbr);
int				syntax_error(char *str_nbr);

void			stack_init(stack_node **a, char **argv, bool flag_argc_2);
void			init_nodes(stack_node *a, stack_node *b);
void			set_current_position(stack_node *stack);
void			set_price(stack_node *a, stack_node *b);
void			set_cheapest(stack_node *b);

//*** Stack creation ***
void			validator(stack_node **a, char **argv, bool flag_argc_2);
void			init_nodes(stack_node *a, stack_node *b);
void			set_current_position(stack_node *stack);
void			set_price(stack_node *a, stack_node *b);
void			set_cheapest(stack_node *b);

#endif
