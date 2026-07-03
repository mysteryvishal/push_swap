/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 08:20:53 by vmistry           #+#    #+#             */
/*   Updated: 2026/07/03 15:15:16 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* sort_3:

Sorts a stack of 3 elements in ascending order using minimal operations.
Logic:
- If the first element is greater than the third, rotate up (ra).
- Else if the first element is greater than the second, swap (sa).
- Else if the second element is greater than the third, swap and 
rotate (sa + ra).

Ensures the 3 elements are sorted in at most 2 operations.
*/
void	sort_3(t_list **lst)
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
}

/* sort_5:

Sorts a stack of 5 elements using the following strategy:
1. Push the two smallest elements to stack B (using pb).
2. Sort the remaining 3 elements in stack A using sort_3.
3. Push the two elements back from stack B to stack A (using pa).
*/
void	sort_5(t_list **a, t_list **b)
{
	int	min_val;

	while (ft_lstsize(*a) > 3)
	{
		min_val = find_min(*a);
		rotate_to_position(a, find_position(*a, min_val));
		pb(a, b);
	}
	sort_3(a);
	while (*b)
		pa(a, b);
}
