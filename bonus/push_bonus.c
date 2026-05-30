/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/30 10:35:09 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/30 11:16:02 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

// Silent versions of the push_swap operations

void	pa(t_list **a, t_list **b)
{
	t_list	*next_b;

	if (!(*b))
		return ;
	next_b = (*b)->next;
	ft_lstadd_front(a, *b);
	(*b) = next_b;
}

void	pb(t_list **a, t_list **b)
{
	t_list	*next_a;

	if (!(*a))
		return ;
	next_a = (*a)->next;
	ft_lstadd_front(b, *a);
	(*a) = next_a;
}
