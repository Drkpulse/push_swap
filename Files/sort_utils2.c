/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:44:55 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/04 16:44:55 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_abs(int nbr)
{
    if(nbr < 0)
        nbr = nbr * -1;
    return(nbr);
}

int get_moves(int index, int target_index)
{
    if(index > target_index)
        return(index);
    if(target_index > index)
        return(target_index);
    return(index);
}