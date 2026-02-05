/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:03:57 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/05 08:26:15 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// dispatch function based on size `n` of stack
// – n <= 5 ––> Quicksort
// – n > 5  ––> Radix sort

int	sort(t_list a, t_list b)
{
	int	n;

	n = ft_lstsize(&a);
	if (n <= 5)
		return (sort_small(a, b));
	else
		return (sort_large(a, b));
}
