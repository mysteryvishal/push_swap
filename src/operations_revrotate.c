/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_revrotate.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:32:11 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/15 06:35:33 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Reverse Rotate (rra, rrb, rrr)
// Move bottom node to top
// Before: [3] -> [1] -> [5] -> NULL
// After:  [5] -> [3] -> [1] -> NULL

static void	rev_rotate(t_list **lst)
{
	t_list	*last;
	t_list	*prev;

	ft_printf("rr: %p\n", *lst);
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
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **a, t_list **b)
{
	rev_rotate(a);
	rev_rotate(b);
	write(1, "rrr\n", 4);
}
