/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:26:12 by joseferr          #+#    #+#             */
/*   Updated: 2024/02/21 15:26:12 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	c_swapations(t_cNode **stack)
{
	long	temp;

	if (*stack && (*stack)->next)
	{
		temp = (*stack)->number;
		(*stack)->number = (*stack)->next->number;
		(*stack)->next->number = temp;
	}
}

void	c_sa(t_cNode **stack)
{
	c_swapations(stack);
}

void	c_sb(t_cNode **stack)
{
	c_swapations(stack);
}

void	c_ss(t_cNode **astack, t_cNode **bstack)
{
	c_swapations(astack);
	c_swapations(bstack);
}
