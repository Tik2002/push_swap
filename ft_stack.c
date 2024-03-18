/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/18 20:25:52 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	pushfront(int n, t_stack *stack)
{
	t_node	*new;

	new = ft_new_node(n);
	if (!stack->m_head)
	{
		stack->m_head = new;
		stack->m_head->next = new;
		stack->m_head->prev = new;
	}
	else
	{
		new->next = stack->m_head;
		new->prev = stack->m_head->prev;
		new->prev->next = new;
		stack->m_head->prev = new;
		stack->m_head = new;
	}
}

void	ft_rotate(t_stack **stack)
{
	(*stack)->m_head = (*stack)->m_head->next;
}

void	ft_rev_rotate(t_stack **stack)
{
	(*stack)->m_head = (*stack)->m_head->prev;
}

void	ft_swap(t_stack **stack)
{
	int	tmp;

	if ((!(*stack)->m_head || !(*stack)->m_head->next) && (*stack)->m_head == (*stack)->m_head->next)
		return ;
	tmp = (*stack)->m_head->data;
	(*stack)->m_head->data = (*stack)->m_head->next->data;
	(*stack)->m_head->next->data = tmp;
}

void	ft_push(t_stack **from, t_stack **to)
{
	t_node	*tmp;

	tmp = (*from)->m_head;
	if ((*from)->m_head->next == (*from)->m_head)
	{
		(*from)->m_head->next = 0;
		(*from)->m_head->prev = 0;
		pushfront(tmp->data, *to);
		free(tmp);
	}
	else
	{
		(*from)->m_head = (*from)->m_head->next;
		(*from)->m_head->prev = tmp->prev;
		tmp->prev->next = (*from)->m_head;
		pushfront(tmp->data, *to);
		free(tmp);
	}
}
