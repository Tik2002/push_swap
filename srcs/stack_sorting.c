/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 19:33:46 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/22 19:19:33 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rotate(t_stack *stack)
{
	if (!stack->m_head)
		return ;
	stack->m_head = stack->m_head->next;
	ft_printf("r%c\n", stack->name);
}

void	ft_reverse_rotate(t_stack *stack)
{
	if (!stack->m_head)
		return ;
	stack->m_head = stack->m_head->prev;
	ft_printf("rr%c\n", stack->name);
}

void	ft_swap(t_stack *stack)
{
	int	tmp;

	if (!stack->m_head || stack->m_head == stack->m_head->next)
		return ;
	tmp = stack->m_head->data;
	stack->m_head->data = stack->m_head->next->data;
	stack->m_head->next->data = tmp;
	ft_printf("s%c\n", stack->name);
}
