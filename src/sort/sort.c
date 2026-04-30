/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:03:57 by vmistry           #+#    #+#             */
/*   Updated: 2026/04/30 11:06:31 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// dispatch function based on size `n` of stack
// – n <= 5 ––> Quicksort
// – n > 5  ––> Radix sort

// TODO: if n isn't used for any calculations besides determining
// which sorting algorithm to use, then don't bother counting it all.
// Just aim to see if it's <= 5 or not.

int	sort(t_list **a, t_list **b)
{
	int	n;

	if (is_sorted(a))
		return (0);
	n = ft_lstsize(*a);
	if (n == 2)
	{
		sa(a);
		return (0);
	}
	else if (n <= 3)
		return (sort_3(a));
	else if (n <= 5)
		return (sort_5(a, b));
	else
		return (sort_large(a, b));
}
