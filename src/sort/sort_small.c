/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:53 by vmistry           #+#    #+#             */
/*   Updated: 2026/04/30 11:13:42 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// TODO verify protections for sort_3
int	sort_3(t_list **lst)
{
	int	*one;
	int	*two;
	int	*three;

	one = (*lst)->content;
	two = ((*lst)->next)->content;
	three = ft_lstlast(*lst)->content;
	while (!((*one < *two) && (*two < *three)))
	{
		one = (*lst)->content;
		two = ((*lst)->next)->content;
		three = ft_lstlast(*lst)->content;
		if (*one > *three)
			ra(lst);
		else if (*one > *two)
			sa(lst);
		else if (*two > *three)
		{
			sa(lst);
			ra(lst);
		}
	}
	return (0);
}

// TODO verify protection for sort_5
int	sort_5(t_list **a, t_list **b)
{
	int	min_val;
	int	min_idx;

	while (ft_lstsize(*a) > 3)
	{
		min_val = find_min(*a);
		min_idx = find_position(*a, min_val);

		if (min_idx <= ft_lstsize(*a))
			while (find_position(*a, min_val) != 0)
				ra(a);
		else
			while (find_position(*a, min_val) != 0)
				rra(a);
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
	return (0);
}
