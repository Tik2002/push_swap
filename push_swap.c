/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/14 20:36:50 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*push_swap(t_stack **a, t_stack **b, int ac)
{
	while (ft_not_sorted((*a)->m_head))
	{
		if (ft_sorted((*a)->m_head))
		{
			print_stack(*a, ac);
			// if (1)
				ft_rotate(a);
			// else
			// 	ft_rev_rotate(a);
		}
	}
	print_stack(*a, ac);
	// ft_push(a, b);
	return (0);
}
