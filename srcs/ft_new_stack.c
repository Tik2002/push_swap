/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:24:25 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 20:02:51 by tigpetro         ###   ########.fr       */
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
	new->prev = 0;
	return (new);
}

t_stack	*ft_new_stack(void)
{
	t_stack *stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->m_head = 0;
	return (stack);
}

void	pushback(int n, t_stack *stack)
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
		new->prev = stack->m_head->prev;
		new->next = stack->m_head;
		stack->m_head->prev = new;
		new->prev->next = new;
	}
}

int	min_data(t_node *const head)
{
	int		value;
	t_node	*tmp;

	tmp = head->next;
	value = head->data;
	while (tmp != head)
	{
		if (tmp->data < value)
			value = tmp->data;
		tmp = tmp->next;
	}
	return (value);
}

int	max_data(t_node *const head)
{
	int		value;
	t_node	*tmp;

	tmp = head->next;
	value = head->data;
	while (tmp != head)
	{
		if (tmp->data > value)
			value = tmp->data;
		tmp = tmp->next;
	}
	return (value);
}
