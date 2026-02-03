/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:30:06 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 10:55:33 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap first 2 nodes in stack a
void	sa(t_list **a)
{
	int	tmp;

	if (!(*a) || !(*a)->next)
		return ;
	tmp = (*a)->content;
	(*a)->content = (*a)->next->content;
	(*a)->next->content = tmp;
	write(1, "sa\n", 3);
}
// Swap first 2 nodes in stack b
void	sb(t_list **b)
{
	int	tmp;

	if (!(*b) || !(*b)->next)
		return ;
	tmp = (*b)->content;
	(*b)->content = (*b)->next->content;
	(*b)->next->content = tmp;
	write(1, "sb\n", 3);
}
// Swap first 2 nodes in stack a and b
void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
	write(1, "ss\n", 3);
}
