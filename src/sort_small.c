/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:53 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/08 00:59:49 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO figure out protections for sort_3
int	sort_3(t_list **a)
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
// TODO move to sort_utils function
int	get_min_index(t_list **a)
{
	int	idx;
	int	idx_min;
	int	*min;
	t_list	*current;

	idx = 0;
	idx_min = 0;
	current = *a;
	min = (int *) current->content;
	while (current)
	{
		if ((*(int *)current->content) < *min)
		{
			min = current->content;
			idx_min = idx;
		}
		idx++;
		current = current->next;
	}
	return (idx_min);
}

// TODO add protections to sort_5
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
			rra(b);
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

// TODO check error handling once sort_3 and sort_5 are fixed
int	sort_small(t_list **a, t_list **b, int n)
{
	if (n <= 3)
		return (sort_3(a));
	else
		return (sort_5(a, b));
	error_exit(a, b);
}
