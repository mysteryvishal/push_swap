/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:27:14 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/08 00:52:04 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	free_split(char **numbers)
{
	size_t	i;
	size_t	n;

	ft_printf("\n--\tfunction: free_split\t\t--\n");
	if (!numbers)
		return ;
	n = 0;
	while (numbers[n])
		n++;
	i = 0;
	while (i < n)
	{
		free(numbers[i]);
		i++;
	}
	free(numbers);
}

static t_list	*build_stack(char **numbers, int split)
{
	t_list	*stack;
	size_t	i;
	t_list	*node;
	int	*val;

	ft_printf("\n--\tfunction: build\t\t--\n");
	i = 0;
	stack = NULL;
	while (numbers[i])
	{
		val = malloc(sizeof(int));
		if (!val)
			return (NULL);
		*val = ft_atoi(numbers[i]);
		node = ft_lstnew(val);
		if (!node)
			return (ft_lstclear(&stack, free), NULL);
		ft_lstadd_back(&stack, node);
		i++;
	}
	if (split)
		free_split(numbers);
	return (stack);
}

t_list	*parse_args(int argc, char **argv)
{
	ft_printf("\n--\tfunction: parse\t\t--\n");
	if (argc == 2)
		return (build_stack(ft_split(argv[1], ' '), 1));
	else
		return (build_stack(&argv[1], 0));
}
