/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:25:23 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/29 15:34:56 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Phase 1: Push all but 3 to B
// Phase 2: Sort remaining 3
// Phase 3: Push back from B (this is the complex part)
// Phase 4: Final rotation to put min at top

// Finds best move in B (lowest cost to push to A) and returns ops for A and B
static void	best_move(t_list **a, t_list **b, int *pos_a, int *pos_b)
{
	t_list	*cur;
	int		i;
	int		cost;
	int		steps_a;
	int		best;

	best = INT_MAX;
	i = 0;
	cur = *b;
	while (cur)
	{
		steps_a = get_steps(ft_lstsize(*a),
				get_target_pos(*a, *(int *)cur->content));
		cost = move_cost(steps_a, get_steps(ft_lstsize(*b), i));
		if (cost < best)
		{
			best = cost;
			*pos_a = steps_a;
			*pos_b = get_steps(ft_lstsize(*b), i);
		}
		cur = cur->next;
		i++;
	}
}

// Performs the best move found by best_move: simultaneous rotations + final push
static void	do_move(t_list **a, t_list **b, int pos_a, int pos_b)
{
	while (pos_a > 0 && pos_b > 0)
	{
		rr(a, b);
		pos_a--;
		pos_b--;
	}
	while (pos_a < 0 && pos_b < 0)
	{
		rrr(a, b);
		pos_a++;
		pos_b++;
	}
	finish_rotations(a, b, pos_a, pos_b);
	pa(a, b);
}

// Main sorting function for large stacks
// 	1. Push all but 3 to B
// 	2. Sort remaining 3 in A
// 	3. For each element in B, calculate best move to push to A
// 	4. Perform best move (simultaneous rotations + push)
// 	5. Final rotation to put min at top
int	sort_large(t_list **a, t_list **b)
{
	int	pos_a;
	int	pos_b;

	while (ft_lstsize(*a) > 3)
		pb(a, b);
	sort_3(a);
	while (*b)
	{
		best_move(a, b, &pos_a, &pos_b);
		do_move(a, b, pos_a, pos_b);
	}
	rotate_to_position(a, find_position(*a, find_min(*a)));
	return (0);
}
