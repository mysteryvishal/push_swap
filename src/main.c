/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 07:26:49 by vmistry           #+#    #+#             */
/*   Updated: 2026/02/03 09:27:12 by vmistry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
    	t_list	*b;

	if (argc < 2)
		return (1);
	a = parse_args(argc, argv);
	b = NULL;
	// TODO: sorting logic here
	
	ft_lstclear(&a, ft_lstdelone);
	ft_lstclear(&b, ft_lstdelone);
	return (0);
}
