/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 17:25:23 by vmistry           #+#    #+#             */
/*   Updated: 2026/06/25 14:05:09 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Phases of the algorithm for large stacks:
Phase 1: Push all but 3 to B
Phase 2: Sort remaining 3
Phase 3: Push back from B
Phase 4: Final rotation to put min at top

Greedy cost-based insertion for Phase 3 involves:
- best_move to find lowest cost move in B to push to A
- do_move to perform the move (simultaneous rotations + push)
- finish_rotations to handle any remaining rotations after simultaneous ones

Function flow:
best_move -> do_move -> finish_rotations
*/

#include "push_swap.h"

/* best_move:

Iterates through B to find the move with the lowest cost to push to A.
Cost is calculated based on:
- Steps to rotate A to target position for the value from B
- Steps to rotate B to bring the value to top
*/
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

/* do_move:

Performs the best move determined by best_move:
- Overlapping steps in A and B for simultaneous rotations (rr or rrr)
- Remaining steps in A or B are handled by finish_rotations
*/
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

/* sort_large:

Main sorting function for large stacks
	1. Push all but 3 to B
	2. Sort remaining 3 in A
	3. For each element in B, calculate best move to push to A
	4. Perform best move (simultaneous rotations + push)
	5. Final rotation to put min at top
*/
void	sort_large(t_list **a, t_list **b)
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
}
