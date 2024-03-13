/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:57:26 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/12 22:57:26 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMON_H
# define COMMON_H
# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct Node_cStack
{
	long				number;
	struct Node_cStack	*next;
}	t_cNode;

// GNL Functions
char	*get_next_line(int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *string, int searchedChar );

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elementCount, size_t elementSize);

size_t	ft_strlen(const char *theString);

// Swap Fucntions
void		c_swapations(t_cNode **stack);
void		c_sa(t_cNode **stack);
void		c_sb(t_cNode **stack);
void		c_ss(t_cNode **astack, t_cNode **bstack);

// Rotation Functions
void		c_rotations(t_cNode **stack);
void		c_ra(t_cNode **stack);
void		c_rb(t_cNode **stack);
void		c_rr(t_cNode **astack, t_cNode **bstack);
void		c_revrotate(t_cNode **stack);
void		c_rra(t_cNode **stack);
void		c_rrb(t_cNode **stack);
void		c_rrr(t_cNode **astack, t_cNode **bstack);

// Push Functions
void		c_push(t_cNode **frststack, t_cNode **lststack);
void		c_pa(t_cNode **bstack, t_cNode **astack);
void		c_pb(t_cNode **astack, t_cNode **bstack);

// Checker Functions
int			c_stacksize(t_cNode **stack);
bool		c_stack_sorted(t_cNode *stack);
void		c_free_stack(t_cNode **stack);

// Validation Functions
int	c_validator(t_cNode **stack, char **argv, int argc);
bool	c_syntax_error(char *str_nbr);
bool	c_duplicates(char **argv);
void	c_ini_stack(t_cNode **stack, char **argv);
void	c_catch_error(t_cNode **a, t_cNode **b, char **argv, bool argv_f);
#endif
