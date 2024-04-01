/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:33:46 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/01 19:59:06 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate(t_stack *stack)
{
	stack->m_head = stack->m_head->next;
}

void	ft_reverse_rotate(t_stack *stack)
{
	stack->m_head = stack->m_head->prev;
}

void	ft_swap(t_stack *stack)
{
	int	tmp;

	tmp = stack->m_head->data;
	stack->m_head->data = stack->m_head->next->data;
	stack->m_head->next->data = tmp;
}
