/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:34:02 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/30 11:15:50 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Silent versions of the push_swap operations

static void	swap(t_list **lst)
{
	t_list	*n1;
	t_list	*n2;

	if (!(*lst) || !(*lst)->next)
		return ;
	n1 = *lst;
	n2 = n1->next;
	n1->next = n2->next;
	n2->next = n1;
	*lst = n2;
}

void	sa(t_list **a)
{
	swap(a);
}

void	sb(t_list **b)
{
	swap(b);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
}
