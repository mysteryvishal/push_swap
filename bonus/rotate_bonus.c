/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:36:36 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/30 11:15:57 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Silent versions of the push_swap operations

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
}

void	rb(t_list **b)
{
	rotate(b);
}

void	rr(t_list **a, t_list **b)
{
	rotate(a);
	rotate(b);
}
