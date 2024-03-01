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
	int argv_f;

	a = NULL;
	b = NULL;
	i = 1;
	argv_f = 0;

	if (argc == 1 || (2 == argc && !argv[1][0]))
		return (0);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		argv_f = 1;
		i = 0;
	}	
	validator(&a, argv + i);
	if (stack_sorted(a))
		return (0);
	if (stacksize(&a) == 3)
		tiny_sort(&a);
	else
		thelastsort(&a, &b);

	free_stack(&a);
	free_stack(&b);
	
	if(argv_f)
		free_argv(argv);
	

	// Small Sort 5 Numbers

	// Sort 100 Numbers

	// Big Sort 100+ Numbers

	return(0);
}
