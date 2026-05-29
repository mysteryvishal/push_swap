/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 12:00:00 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/29 15:17:48 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Returns signed steps to rotate pos to top: positive = ra, negative = rra
int	get_steps(int size, int pos)
{
	if (pos <= size / 2)
		return (pos);
	return (-(size - pos));
}

// Same direction (both pos/neg): simultaneous rr/rrr → cost = max(|a|,|b|)
// Opposite direction: separate rotations → cost = |a| + |b|
int	move_cost(int steps_a, int steps_b)
{
	int	abs_a;
	int	abs_b;

	if (steps_a < 0)
		abs_a = -steps_a;
	else
		abs_a = steps_a;
	if (steps_b < 0)
		abs_b = -steps_b;
	else
		abs_b = steps_b;
	if ((steps_a >= 0 && steps_b >= 0) || (steps_a < 0 && steps_b < 0))
	{
		if (abs_a > abs_b)
			return (abs_a);
		return (abs_b);
	}
	return (abs_a + abs_b);
}

// Handles single stack rotations after simultaneous rr/rrr
void	finish_rotations(t_list **a, t_list **b, int steps_a, int steps_b)
{
	while (steps_a > 0)
	{
		ra(a);
		steps_a--;
	}
	while (steps_a < 0)
	{
		rra(a);
		steps_a++;
	}
	while (steps_b > 0)
	{
		rb(b);
		steps_b--;
	}
	while (steps_b < 0)
	{
		rrb(b);
		steps_b++;
	}
}

// Finds target position in A for given B value
// Checking pairs of elements by circularly iterating through A
// 	(if value fits between prev and current, return current position)
int	get_target_pos(t_list *stack, int value)
{
	t_list	*current;
	t_list	*prev;
	int		pos;
	int		pv;
	int		cv;

	current = stack;
	prev = ft_lstlast(stack);
	pos = 0;
	while (current)
	{
		pv = *(int *)prev->content;
		cv = *(int *)current->content;
		if ((pv < cv && pv < value && value <= cv)
			|| (pv > cv && (value > pv || value <= cv)))
			return (pos);
		prev = current;
		current = current->next;
		pos++;
	}
	return (0);
}
