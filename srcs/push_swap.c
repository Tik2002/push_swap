/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 20:14:04 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push_swap(t_stack *a, t_stack *b, int ac)
{
	while (!ft_is_sorted(a->m_head) && !(b->m_head))
	{
		if (ft_offset_sort(a->m_head, 1) || ft_offset_sort(b->m_head, 0))
		{
			while (ft_offset_sort(a->m_head, 1) == 1 || ft_offset_sort(b->m_head, 0) == 1)
			{
				if (!ft_offset_sort(a->m_head, 1))
					rb(b, 1);
				else if (!ft_offset_sort(b->m_head, 0))
					ra(a, 1);
				else
					rr(a, b);
			}
			while (ft_offset_sort(a->m_head, 1) == -1 || ft_offset_sort(b->m_head, 0) == -1)
			{
				if (!ft_offset_sort(a->m_head, 1))
					rrb(b, 1);
				else if (!ft_offset_sort(b->m_head, 0))
					rra(a, 1);
				else
					rrr(a, b);
			}
		}
		else if (a->m_head->data < a->m_head->next->data || b->m_head->data > b->m_head->next->data)
			if (a->m_head->data < a->m_head->next->data || b->m_head->data > b->m_head->next->data)
				ss(a, b);
			else if (a->m_head->data < a->m_head->next->data)
				sa(a, 1);
			else
				sb(b, 1);
		else
			ft_push(a, b);
	}
}
