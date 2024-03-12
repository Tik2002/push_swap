/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:24:25 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/12 19:25:38 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_node	*ft_new_node(int n)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->data = n;
	new->next = 0;
	return (new);
}

t_stack	*ft_new_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->m_head = 0;
	stack->m_tail = 0;
	return (stack);
}

void	pushback(int n, t_stack *stack)
{
	t_node	*new;

	new = ft_new_node(n);
	if (!stack->m_head)
		stack->m_head = new;
	if (!stack->m_tail)
		stack->m_tail = new;
	stack->m_tail->next = new;
	stack->m_tail = new;
	new->next = stack->m_head;
}
