/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:53 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/20 18:38:14 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO write protection for sort_3 (if any)
int	sort_3(t_list **lst)
{
	int	*one;
	int	*two;
	int	*three;

	one = (*lst)->content;
	two = ((*lst)->next)->content;
	three = ft_lstlast(*lst)->content;
	if (!(*one) || !(*two) || !(*three))
		return (1);
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

// TODO write protection for sort_5 (if any)
int	sort_5(t_list **a, t_list **b)
{
	int	idx_min;

	ft_printf("\n--\tfunction: sort_5\t\t--\n");
	idx_min = get_min_index(a);
	while (ft_lstsize(*a) != 3)
	{
		if (idx_min == 0)
			pb(a, b);
		if (idx_min > 3)
			rra(a);
		else
			ra(a);
		idx_min = get_min_index(a);
		ft_printf("idx_min = %d\n", idx_min);
		print_stack(a);
		print_stack(b);
	}
	sort_3(a);
	while(*b)
		pa(a, b);
	ft_printf("sorted:\n");
	print_stack(a);
	print_stack(b);
	return(0);
}

// TODO write protections
int	sort_small(t_list **a, t_list **b, int n)
{
	ft_printf("\n--\tfunction: sort_small\t\t--\n");
	if (n <= 3)
		return (sort_3(a));
	else
		return (sort_5(a, b));
	error_exit(a, b);
}
