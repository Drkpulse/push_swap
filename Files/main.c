/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joseferr <joseferr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:24:22 by joseferr          #+#    #+#             */
/*   Updated: 2024/03/18 13:33:31 by joseferr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, char **argv)
{
	t_Node		*stack_a;
	t_Node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		catch_error(NULL, NULL, NULL, 2);
	validator(&stack_a, argv, argc);
	if (stack_sorted(stack_a))
		ft_clean(&stack_a, NULL, argv);
	else if (stacksize(&stack_a) == 2)
		two_numbers_one_function(&stack_a);
	else if (stacksize(&stack_a) == 3)
		tiny_sort(&stack_a);
	else if (stacksize(&stack_a) <= 5)
		sorting_five(&stack_a, &stack_b);
	else
		thelastsort(&stack_a, &stack_b);
	ft_clean(&stack_a, &stack_b, NULL);
	return (0);
}
