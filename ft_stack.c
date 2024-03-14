/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/14 20:24:20 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pushfront(int n, t_stack *stack)
{
	t_node	*new;

	new = ft_new_node(n);
	if (!stack->m_head)
		stack->m_head = new;
	if (!stack->m_tail)
		stack->m_tail = new;
	new->next = stack->m_head;
	stack->m_tail->next = new;
}

void	ft_rotate(t_stack **stack)
{
	(*stack)->m_head = (*stack)->m_head->next;
}

void	ft_rev_rotate(t_stack **stack)
{
	while ((*stack)->m_head != (*stack)->m_tail)
		(*stack)->m_head = (*stack)->m_head->next;
}

void	ft_swap(t_stack **stack)
{
	t_node	*tmp;
	t_node	*tmp_next;

	if (!(*stack)->m_head || !(*stack)->m_head->next)
		return ;
	tmp = (*stack)->m_head;
	tmp_next = (*stack)->m_head->next;
	if ((*stack)->m_head->next != (*stack)->m_tail)
	{
		(*stack)->m_head = tmp_next;
		tmp->next = tmp_next->next;
		(*stack)->m_head->next = tmp;
		(*stack)->m_tail->next = (*stack)->m_head;
	}
	else
		(*stack)->m_head = (*stack)->m_tail;
}

void	ft_push(t_stack **from, t_stack **to)
{
	t_node	*tmp;

	tmp = (*from)->m_head;
	(*from)->m_head = (*from)->m_head->next;
	(*from)->m_tail->next = (*from)->m_head;
	pushfront(tmp->data, *to);
	free(tmp);
}
