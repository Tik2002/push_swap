/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:33:46 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 19:37:10 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	rb(t_stack *b, int flag)
{
	b->m_head = b->m_head->next;
	if (flag)
		ft_printf("rb\n");
}

void	rrb(t_stack *b, int flag)
{
	b->m_head = b->m_head->prev;
	if (flag)
		ft_printf("rrb\n");
}

void	sb(t_stack *b, int flag)
{
	int	tmp;

	if (!b->m_head || b->m_head == b->m_head->next)
		return ;
	tmp = b->m_head->data;
	b->m_head->data = b->m_head->next->data;
	b->m_head->next->data = tmp;
	if (flag)
		ft_printf("sb\n");
}

