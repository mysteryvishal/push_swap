/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:27:14 by vmistry           #+#    #+#             */
/*   Updated: 2026/06/15 14:35:49 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* is_valid_int:

Checks if given string is a valid integer within INT_MIN and INT_MAX.
- Handles optional leading '+' or '-' sign.
- Ensures the string contains only digits after the optional sign.
- Returns 1 if valid, otherwise returns 0.
*/
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

/* has_duplicate:

Checks if the given value already exists in the stack.
- Returns 1 if a duplicate is found, otherwise returns 0.
*/
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

/* parse_cleanup:

Frees all allocated memory for the stack and split numbers.
- If `split` is true, also frees the array of split strings.
- Returns NULL for convenient error handling in the caller.
*/
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

/* build_stack:

Builds a linked list stack from an array of string numbers.
- Validates each string as a proper integer.
- Checks for duplicates in the stack.
- On any error, frees all allocated memory and returns NULL.
*/
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

/* parse_args:

Parses command-line arguments into a linked list stack.

- If argc == 2, splits the single string argument by spaces.
- Otherwise, treats each argv[i] (i > 0) as a separate number.
*/
t_list	*parse_args(int argc, char **argv)
{
	if (argc == 2)
		return (build_stack(ft_split(argv[1], ' '), 1));
	else
		return (build_stack(&argv[1], 0));
}
