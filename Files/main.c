/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:24:22 by joseferr          #+#    #+#             */
/*   Updated: 2024/01/24 17:11:37 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char** argv)
{
	Node_Stack	*a;
	Node_Stack	*b;
	int i;

	a = NULL;
	b = NULL;
	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (0);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	i = 1;
	if (argc == 2)
		i = 0;

	validator(&a, argv + i);

	if (stack_sorted(a))
		return (0);
	
	tiny_sort(&a);
	
	while(a)
	{
		printf("%ld\n", a->number);
		a = a->next;
	}

	// Sorting the stack A

	// Tiny Sort 3 Numbers

	// Small Sort 5 Numbers

	// Sort 100 Numbers

	// Big Sort 100+ Numbers

	// Printing the instructions

	return(0);
}
