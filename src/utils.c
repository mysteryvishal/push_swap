/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:36:22 by vmistry           #+#    #+#             */
/*   Updated: 2026/04/30 11:15:08 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_list **a, t_list **b)
{
	if (*a || *b)
		clear_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

void	clear_stacks(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
}

void	print_stack(t_list **stack)
{
	t_list	*current;

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

int	is_sorted(t_list **stack)
{
	t_list	*current;

	if (!stack)
		return (-1);
	current = *stack;
	while (current && current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
