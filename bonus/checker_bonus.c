/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/29 00:00:00 by vmistry           #+#    #+#             */
/*   Updated: 2026/05/30 11:32:21 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	execute_operation(t_list **a, t_list **b, char *line)
{
	if (ft_strncmp(line, "sa", 3) == 0)
		return (sa(a), 1);
	else if (ft_strncmp(line, "sb", 3) == 0)
		return (sb(b), 1);
	else if (ft_strncmp(line, "ss", 3) == 0)
		return (ss(a, b), 1);
	else if (ft_strncmp(line, "pa", 3) == 0)
		return (pa(a, b), 1);
	else if (ft_strncmp(line, "pb", 3) == 0)
		return (pb(a, b), 1);
	else if (ft_strncmp(line, "ra", 3) == 0)
		return (ra(a), 1);
	else if (ft_strncmp(line, "rb", 3) == 0)
		return (rb(b), 1);
	else if (ft_strncmp(line, "rr", 3) == 0)
		return (rr(a, b), 1);
	else if (ft_strncmp(line, "rra", 4) == 0)
		return (rra(a), 1);
	else if (ft_strncmp(line, "rrb", 4) == 0)
		return (rrb(b), 1);
	else if (ft_strncmp(line, "rrr", 4) == 0)
		return (rrr(a, b), 1);
	return (0);
}

static int	process_line(t_list **a, t_list **b, char *line)
{
	size_t	len;

	len = ft_strlen(line);
	if (len > 0 && line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (!execute_operation(a, b, line))
		return (free(line), 0);
	free(line);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	*line;

	if (argc < 2)
		return (0);
	b = NULL;
	a = parse_args(argc, argv);
	if (!a)
		error_exit(&a, &b);
	line = get_next_line(0);
	while (line)
	{
		if (!process_line(&a, &b, line))
			error_exit(&a, &b);
		line = get_next_line(0);
	}
	if (is_sorted(&a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (clear_stacks(&a, &b), 0);
}
