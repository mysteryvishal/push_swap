/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:37:44 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/30 11:16:00 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Silent versions of the push_swap operations

static void	rev_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*prev;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	prev = NULL;
	last = *lst;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	if (prev)
		prev->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	rra(t_list **a)
{
	rev_rotate(a);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
}
