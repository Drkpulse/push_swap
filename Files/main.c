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

int	main(int argc, char **argv)
{
	t_Node		*stack_a;
	t_Node		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	validator(&stack_a, argv, argc);
	if (stack_sorted(stack_a))
		ft_clean(&stack_a, NULL, argv);
	if (stacksize(&stack_a) == 3)
		tiny_sort(&stack_a);
	else
		thelastsort(&stack_a, &stack_b);
	ft_clean(&stack_a, &stack_b, NULL);
	return (0);
}
