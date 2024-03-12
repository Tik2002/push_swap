/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/12 19:27:20 by tigpetro         ###   ########.fr       */
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
		ft_rotate(stack);
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

void	ft_push_a(t_stack **a, t_stack **b)
{
	t_node	*tmp;

	tmp = (*a)->m_head;
	(*a)->m_head = (*a)->m_head->next;
	(*a)->m_tail->next = (*a)->m_head;
	pushfront(tmp->data, *b);
	free(tmp);
}
