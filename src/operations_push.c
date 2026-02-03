/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:29:56 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 12:28:35 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Push (pa, pb)
// Remove top node from one stack, add to top of other
// A: [3] -> [1]    		B: [5] -> [2]
// After pa:
// A: [5] -> [3] -> [1]    	B: [2]

void	pa(t_list **a, t_list **b)
{
	t_list	*next_b;

	if (!(*b))
		return ;
	next_b = (*b)->next;
	ft_lstadd_front(a, *b);
	(*b) = next_b;
	write(1, "pa\n", 3);
}

void	pb(t_list **a, t_list **b)
{
	t_list	*next_a;

	if (!(*a))
		return ;
	next_a = (*a)->next;
	ft_lstadd_front(b, *a);
	(*a) = next_a;
	write(1, "pb\n", 3);
}
