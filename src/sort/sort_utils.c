/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:33:27 by vmistry           #+#    #+#             */
/*   Updated: 2026/06/15 14:28:45 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* find_min:

Finds the minimum value in the stack.
*/
int	find_min(t_list *stack)
{
	int		min;
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	min = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content < min)
			min = *(int *)current->content;
		current = current->next;
	}
	return (min);
}

/* find_max:

Finds the maximum value in the stack.
*/
int	find_max(t_list *stack)
{
	int		max;
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	max = *(int *)current->content;
	while (current)
	{
		if (*(int *)current->content > max)
			max = *(int *)current->content;
		current = current->next;
	}
	return (max);
}

/* find_position:

Finds the index of the specified value in the stack.
Returns the index if found, or -1 if not found.
*/
int	find_position(t_list *stack, int value)
{
	t_list	*current;
	int		idx;

	current = stack;
	idx = 0;
	while (current)
	{
		if (*(int *)current->content == value)
			return (idx);
		idx++;
		current = current->next;
	}
	return (-1);
}

/* rotate_to_position:

Rotates the stack to bring the specified element position to the top.

- if position in first half of stack -> rotate up (ra)
- if position in second half of stack -> rotate down (rra)
*/
void	rotate_to_position(t_list **stack, int pos)
{
	int	size;

	size = ft_lstsize(*stack);
	if (pos <= size / 2)
		while (pos--)
			ra(stack);
	else
		while (pos++ < size)
			rra(stack);
}
