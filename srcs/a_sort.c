/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:33:43 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 19:37:09 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ra(t_stack *a, int flag)
{
	a->m_head = a->m_head->next;
	if (flag)
		ft_printf("ra\n");
}

void	rra(t_stack *a, int flag)
{
	a->m_head = a->m_head->prev;
	if (flag)
		ft_printf("rra\n");
}

void	sa(t_stack *a, int flag)
{
	int	tmp;

	if (!a->m_head || a->m_head == a->m_head->next)
		return ;
	tmp = a->m_head->data;
	a->m_head->data = a->m_head->next->data;
	a->m_head->next->data = tmp;
	if (flag)
		ft_printf("sa\n");
}
