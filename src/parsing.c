/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:27:14 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/05 06:56:55 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// TODO free memory from ft_split
static t_list	*build_stack(char **numbers, int split)
{
	t_list	*stack;
	size_t	i;
	int	val;

	(void)split;
	i = 0;
	stack = NULL;
	while(numbers[i])
	{
		val = ft_atoi(numbers[i]);
		ft_lstadd_back(&stack, ft_lstnew(&val));
		i++;
	}
	return (stack);
}

t_list	*parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (build_stack(ft_split(argv[1], ' '), 1));
	else
		return (build_stack(&argv[1], 0));
}
