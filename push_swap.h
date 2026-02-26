/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 22:38:51 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/20 18:34:10 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"


// general utils
void	error_exit(t_list **a, t_list **b);
void	print_stack(t_list **stack);
void	clear_stacks(t_list **a, t_list **b);

// sort utils
int	get_min_index(t_list **a);
int	is_sorted(t_list **lst);

// parsing
t_list	*parse_args(int argc, char **argv);

// operations
void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

// sorting
int	sort(t_list **a, t_list **b);
int	sort_small(t_list **a, t_list **b, int n);
int	sort_3(t_list **a);
int	sort_5(t_list **a, t_list **b);
int	sort_large(t_list **a, t_list **b, int n);
#endif
