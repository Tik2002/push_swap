/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rev_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:44:24 by senate            #+#    #+#             */
/*   Updated: 2024/03/20 20:22:41 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_rev_rotate(t_stack *a, t_stack *b)
{
	// ft_printf("check rev rotate \n");
	// if (ft_rev_sorted(b->m_head) && ft_is_sorted(a->m_head))
	// 	return (0);
	return (ft_offset_sort(a->m_head, 1) == -1
		|| ft_offset_sort(b->m_head, 0) == -1);
}

void	do_rev_rotate(t_stack *a, t_stack *b)
{
	if (check_rev_rotate(a, b))
	{
		if (!ft_offset_sort(a->m_head, 1) && !ft_rev_sorted(b->m_head))
			ft_rotate(b, 1);
		else if (!ft_offset_sort(b->m_head, 0) && !ft_is_sorted(a->m_head))
			ft_rotate(a, 1);
		else if (!ft_rev_sorted(b->m_head) && !ft_is_sorted(a->m_head))
			ft_all_rotate(a, b);
	}
}

