/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:03:57 by vmistry           #+#    #+#             */
/*   Updated: 2026/06/25 14:04:47 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort:

Dispatch function based on stack size `n`

Logic:
	n <= 3 –> hardcoded decision tree
	n <= 5 –> push 2 smallest to B, sort 3, push back
	n >  5 –> greedy cost-based insertion
*/
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
		sort_3(a);
	else if (n <= 5)
		sort_5(a, b);
	else
		sort_large(a, b);
	return (!is_sorted(a));
}
