/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:30:04 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 12:27:44 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Rotate (ra, rb, rr)
// Move top node to bottom
// Before: [3] -> [1] -> [5] -> NULL
// After:  [1] -> [5] -> [3] -> NULL

static void	rotate(t_list **lst)
{
	t_list	*node;

	if (!(*lst) || !(*lst)->next)
		return ;
	node = (*lst);
	(*lst) = (*lst)->next;
	node->next = NULL;
	ft_lstadd_back(lst, node);
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
}
