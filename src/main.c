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

// TODO sort of success/failure signals between functions
// TODO move clear_stacks to utils
void	clear_stacks(t_list **a, t_list **b)
{
	ft_printf("\n--\tfunction: clear\t\t--\n");
	if (*a)
	{
		ft_lstclear(a, free);
		ft_printf("cleared: a\n");
	}
	if (*b)
	{
		ft_lstclear(b, free);
		ft_printf("cleared: b\n");
	}
}

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
