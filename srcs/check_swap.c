/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:46:14 by senate            #+#    #+#             */
/*   Updated: 2024/03/20 01:35:52 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_swap(t_stack *a, t_stack *b)
{
	ft_printf("check swap \n");
	if (!(b->m_head) || b->m_head == b->m_head->next)
	{
		if (a->m_head->data > a->m_head->next->data)
			return (1);
		else
			return (0);
	}
	else
	{
		ft_printf(" result %d\n", a->m_head->data > a->m_head->next->data || b->m_head->data < b->m_head->next->data);
		if (a->m_head->data > a->m_head->next->data
		|| b->m_head->data < b->m_head->next->data)
			return (1);
	}
	return (0);
}

void	do_swap(t_stack *a, t_stack *b)
{
	if (!(b->m_head) || b->m_head->data > b->m_head->next->data || b->m_head == b->m_head->next)
		ft_swap(a, 1);
	else if (b->m_head && a->m_head->data < a->m_head->next->data && b->m_head != b->m_head->next)
		ft_swap(b, 1);
	else
		ft_all_swap(a, b);
}
