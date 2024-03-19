/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 19:47:48 by tigpetro         ###   ########.fr       */
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

void	rr(t_stack *a, t_stack *b)
{
	ra(a, 0);
	rb(b, 0);
	ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a, 0);
	rrb(b, 0);
	ft_printf("rrr\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a, 0);
	sb(b, 0);
	ft_printf("ss\n");
}

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	tmp = from->m_head;
	if (from->m_head->next == from->m_head)
	{
		from->m_head->next = 0;
		from->m_head->prev = 0;
		pushfront(tmp->data, to);
		free(tmp);
	}
	else
	{
		from->m_head = from->m_head->next;
		from->m_head->prev = tmp->prev;
		tmp->prev->next = from->m_head;
		pushfront(tmp->data, to);
		free(tmp);
	}
	ft_printf("p%c\n", from->name);
}
