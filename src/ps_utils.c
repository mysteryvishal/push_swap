/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:36:22 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/08 00:52:17 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_list **a, t_list **b)
{
	ft_printf("\n--\tfunction: error\t\t--\n");
	if (*a || *b)
		clear_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

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

void	print_stack(t_list **stack)
{
	t_list *current;

	current = *stack;
	ft_printf("Stack: ");
	while (current)
	{
		ft_printf("%d", *(int *)current->content);
		if (current->next)
			ft_printf(" -> ");
		current = current->next;
	}
	ft_printf("\n");
}
