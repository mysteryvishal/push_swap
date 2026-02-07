/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:36:22 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/07 18:28:26 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	error_exit(t_list **a, t_list **b)
{
	if (*a || *b)
		clear_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
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
