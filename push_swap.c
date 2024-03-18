/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/18 20:28:14 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap(t_stack **a, t_stack **b, int ac)
{
	while (ft_not_sorted((*a)->m_head))
	{
		ft_rotate(a);
	}
	ft_push(a, b);
	ft_push(a, b);
	while ((*b)->m_head->next)
	{
		ft_push(b, a);
	}
	print_stack(*a, ac);
}
