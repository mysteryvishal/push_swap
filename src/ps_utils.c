/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:36:22 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/05 10:51:38 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
void	print_stack(t_list **stack)
{
	t_list *current;
	
	current = *stack;
	ft_putstr_fd("Stack: ", 1);
	while (current)
	{
		ft_putnbr_fd(*(int *)current->content, 1);
		if (current->next)
			ft_putstr_fd(" -> ", 1);
		current = current->next;
	}
	ft_putstr_fd("\n", 1);
}
