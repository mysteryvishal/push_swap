/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:27:14 by vmistry           #+#    #+#             */
/*   Updated: 2026/04/30 11:02:06 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(const char *s)
{
	long	n;
	int		sign;

	sign = 1;
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	if (*s == '\0')
		return (0);
	n = 0;
	while (ft_isdigit(*s))
		n = n * 10 + (*s++ - '0');
	n *= sign;
	if (n < INT_MIN || n > INT_MAX)
		return (0);
	if (*s != '\0')
		return (0);
	return (1);
}

static int	has_duplicate(t_list *stack, int value)
{
	while (stack)
	{
		if (*(int *)stack->content == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static t_list	*parse_cleanup(t_list **stack, char **numbers, int split)
{
	size_t	i;
	size_t	n;

	if (stack)
		ft_lstclear(stack, free);
	if (split)
	{
		if (!numbers)
			return (NULL);
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
	return (NULL);
}

static t_list	*build_stack(char **numbers, int split)
{
	t_list	*stack;
	t_list	*node;
	size_t	i;
	int		*val;

	i = 0;
	stack = NULL;
	while (numbers[i])
	{
		if (!is_valid_int(numbers[i]))
			return (parse_cleanup(&stack, numbers, split));
		val = malloc(sizeof(int));
		if (!val)
			return (parse_cleanup(&stack, numbers, split));
		*val = ft_atoi(numbers[i]);
		if (has_duplicate(stack, *val))
			return (free(val), parse_cleanup(&stack, numbers, split));
		node = ft_lstnew(val);
		if (!node)
			return (free(val), parse_cleanup(&stack, numbers, split));
		ft_lstadd_back(&stack, node);
		i++;
	}
	return (parse_cleanup(NULL, numbers, split), stack);
}

t_list	*parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (build_stack(ft_split(argv[1], ' '), 1));
	else
		return (build_stack(&argv[1], 0));
}
