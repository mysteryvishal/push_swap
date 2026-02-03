/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_swap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:30:06 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 12:40:52 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Swap (sa, sb, ss)
// Swap the first 2 nodes (this implementation swaps their content/value)
// Before: [3] -> [1] -> [5]
// After:  [1] -> [3] -> [5]

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
	write(1, "sa\n", 3);
}

void	sb(t_list **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_list **a, t_list **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
