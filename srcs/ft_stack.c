/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/21 17:31:43 by tigpetro         ###   ########.fr       */
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

void	ft_push(t_stack *from, t_stack *to, int flag)
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
	if (flag)
		ft_printf("p%c\n", to->name);
}

static void	destroy_subroutine(t_stack *stack, t_node *start, t_node *end)
{
	if (start == end && stack->name != 'a')
		return ;
	stack->name = 'c';
	destroy_subroutine(stack, start->next, end);
	free(start);
}

void	ft_destroy(t_stack *stack)
{
	if (stack->name == 'b')
	{
		free (stack);
		return ;
	}
	destroy_subroutine(stack, stack->m_head, stack->m_head);
	free(stack);
}
