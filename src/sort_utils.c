/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 18:33:27 by vmistry           #+#    #+#             */
/*   Updated: 2026/03/06 07:48:51 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
