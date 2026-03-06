/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:33:27 by vmistry           #+#    #+#             */
/*   Updated: 2026/03/06 09:38:17 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **stack)
{
	t_list	*current;

	if (!stack)
		return (-1);
	current = *stack;
	while (current && current->next)
	{
		if (*(int *)current->content > *(int *)current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_min(t_list *stack)
{
	int		min;
	t_list	*current;

	if (!stack)
		return (0);
	current = stack;
	min = *(int *)current->content;
	while (current && current->next)
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
	while (current && current->next)
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
	int	idx;

	current = stack;
	idx = 0;
	while (current && current->next)
	{
		if (*(int *)current->content == value)
			return (idx);
		idx++;
		current = current->next;
	}
	return (-1);
}