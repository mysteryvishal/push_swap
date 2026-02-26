/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:49 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/08 01:01:56 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO sort out success/failure signals between functions

int	main(int argc, char *argv[])
{
	ft_printf("\n--\tfunction: main\t\t--\n");
	t_list	*a;
    	t_list	*b;

	if (argc < 2)
		return (1);
	a = parse_args(argc, argv);
	b = NULL;
	if (!a)
		error_exit(&a, &b);
	if (sort(&a, &b))
		return (clear_stacks(&a, &b), 1);
	ft_printf("\n--\tcomplete: main\t\t--\n");
	print_stack(&a);
	return (clear_stacks(&a, &b), 0);
}
