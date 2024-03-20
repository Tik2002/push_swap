/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/20 20:27:05 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_pushfront(int n, t_stack *stack)
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

void	ft_all_rotate(t_stack *a, t_stack *b)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	ft_printf("rr\n");
}

void	ft_all_reverse_rotate(t_stack *a, t_stack *b)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	ft_printf("rrr\n");
}

void	ft_all_swap(t_stack *a, t_stack *b)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	ft_printf("ss\n");
}

void	ft_push(t_stack *from, t_stack *to)
{
	t_node	*tmp;

	if (!from->m_head)
		return ;
	tmp = from->m_head;
	if (from->m_head->next == from->m_head)
	{
		ft_pushfront(tmp->data, to);
		free(from->m_head);
		from->m_head = 0;
	}
	else
	{
		from->m_head = from->m_head->next;
		from->m_head->prev = tmp->prev;
		tmp->prev->next = from->m_head;
		ft_pushfront(tmp->data, to);
		free(tmp);
	}
	ft_printf("p%c\n", to->name);
}
