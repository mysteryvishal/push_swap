/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:33:27 by vmistry           #+#    #+#             */
/*   Updated: 2026/03/06 11:38:49 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_target_pos(t_list *stack, int value)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (*(int *)stack->content >= value)
			return (pos);
		stack = stack->next;
		pos++;
	}
	return (0);
}

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
