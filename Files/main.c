/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:24:22 by joseferr          #+#    #+#             */
/*   Updated: 2024/01/23 16:59:39 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);

	// Checking if the stack is sorted

	// Sorting the stack A

	// Tiny Sort 3 Numbers

	// Small Sort 5 Numbers

	// Sort 100 Numbers

	// Big Sort 100+ Numbers

	// Printing the instructions

	return(0);
}
