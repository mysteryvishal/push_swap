/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:49 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/07 18:31:41 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO sort of success/failure signals between functions
// TODO move clear_stacks to utils
void	clear_stacks(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
    	t_list	*b;

	if (argc < 2)
		return (1);
	a = parse_args(argc, argv);
	b = NULL;
	if (!a)
		error_exit(&a, &b);
	if (!sort(&a, &b))
		return (clear_stacks(&a, &b), 1);
	return (clear_stacks(&a, &b), 0);
}
