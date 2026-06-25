/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/04 10:36:22 by vmistry           #+#    #+#             */
/*   Updated: 2026/06/25 14:04:05 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* error_exit:

Called on any parsing or sorting error. Printing "Error\n" to stderr.
- Frees any allocated stacks to prevent memory leaks.
- Exits the program with a non-zero status to indicate failure.
*/
void	error_exit(t_list **a, t_list **b)
{
	if (*a || *b)
		clear_stacks(a, b);
	write(2, "Error\n", 6);
	exit(1);
}

/* clear_stacks:

Frees all memory allocated for stacks A and B.
- Uses ft_lstclear to free each node's content and the nodes themselves.
*/
void	clear_stacks(t_list **a, t_list **b)
{
	if (*a)
		ft_lstclear(a, free);
	if (*b)
		ft_lstclear(b, free);
}

/* is_sorted:
Checks if the stack is sorted in ascending order.
- Returns 1 if sorted, 0 if not, -1 on error.
*/
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
