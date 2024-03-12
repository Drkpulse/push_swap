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
	int			argv_f;

	stack_a = NULL;
	stack_b = NULL;
	argv_f = 0;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	argv_f = validator(&stack_a, argv, argc);
	if (stack_sorted(stack_a))
		ft_clean(&stack_a, NULL, argv, argv_f);
	if (stacksize(&stack_a) == 3)
		tiny_sort(&stack_a);
	else
		thelastsort(&stack_a, &stack_b);
	ft_clean(&stack_a, &stack_b, argv, argv_f);
	return (0);
}
