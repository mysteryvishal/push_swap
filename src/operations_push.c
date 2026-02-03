/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:29:56 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 11:19:58 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Remove top node from stack b, add to top of stack a
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
// Remove top node from stack a, add to top of stack b
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
