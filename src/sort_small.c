/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:53 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/05 10:48:18 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	sort_3(t_list **a)
{
	int	*one;
	int	*two;
	int	*three;

	one = (*a)->content;
	two = ((*a)->next)->content;
	three = ft_lstlast(*a)->content;
	while (!((*one < *two) && (*two < *three)))
	{
		one = (*a)->content;
		two = ((*a)->next)->content;
		three = ft_lstlast(*a)->content;
		if (*one > *three)
			ra(a);
		else if (*one > *two)
			sa(a);
		else if (*two > *three)
		{
			sa(a);
			ra(a);
		}
	}
	return (0);
}

// TODO add sort for <= 5
int	sort_small(t_list **a, t_list **b, int n)
{
	if (n <= 3)
		return (sort_3(a));
	else
		return (1);
	return (0);
}
