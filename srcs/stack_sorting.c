/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:33:46 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/20 22:14:54 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate(t_stack *a, int flag)
{
	a->m_head = a->m_head->next;
	if (flag)
		ft_printf("r%c\n", a->name);
}

void	ft_reverse_rotate(t_stack *a, int flag)
{
	a->m_head = a->m_head->prev;
	if (flag)
		ft_printf("rr%c\n", a->name);
}

void	ft_swap(t_stack *a, int flag)
{
	int	tmp;

	tmp = a->m_head->data;
	a->m_head->data = a->m_head->next->data;
	a->m_head->next->data = tmp;
	if (flag)
		ft_printf("s%c\n", a->name);
}
