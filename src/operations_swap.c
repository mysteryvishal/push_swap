/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:30:06 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 12:09:21 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **lst)
{
	int	tmp;

	if (!(*lst) || !(*lst)->next)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

// Swap first 2 nodes in stack a
void	sa(t_list **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

// Swap first 2 nodes in stack b
void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

// Swap first 2 nodes in stack a and b
void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
