/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:49 by vmistry           #+#    #+#             */
/*   Updated: 2026/04/30 11:14:49 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO sort out success/failure signals between functions

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
	if (sort(&a, &b))
		return (clear_stacks(&a, &b), 1);
	return (clear_stacks(&a, &b), 0);
}
