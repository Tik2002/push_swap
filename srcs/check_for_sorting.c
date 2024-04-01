/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_for_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:47:04 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/01 20:17:38 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	rotate(t_stack *a, t_stack *b)
{
	if (!a->m_head && !b->m_head)
		return ;
	else if (!b->m_head && ft_offset_sort(a->m_head, a->name) == 1)
	{
		ft_rotate(a);
		ft_printf("r%c\n", a->name);
	}
	else if (!a->m_head && ft_offset_sort(b->m_head, b->name) == 1)
	{
		ft_rotate(b);
		ft_printf("r%c\n", b->name);
	}
	else
	{
		ft_rotate(a);
		ft_rotate(b);
		ft_printf("rr\n");
	}
}

void	reverse_rotate(t_stack *a, t_stack *b)
{
	if (!a->m_head && !b->m_head)
		return ;
	else if (!b->m_head && ft_offset_sort(a->m_head, a->name) == -1)
	{
		ft_reverse_rotate(a);
		ft_printf("rr%c\n", a->name);
	}
	else if (!a->m_head && ft_offset_sort(b->m_head, b->name) == -1)
	{
		ft_reverse_rotate(b);
		ft_printf("rr%c\n", b->name);
	}
	else
	{
		ft_reverse_rotate(a);
		ft_reverse_rotate(b);
		ft_printf("rrr\n");
	}
}

static int	ft_check_for_swap(t_node *const head_a, t_node *const head_b, char c)
{

	if (head_a->data > head_a->next->data && ft_till_sorted(head_a->next->next, head_a))
		return (1);
	return (0);
}

void	swap(t_stack *a, t_stack *b)
{
	int	tmp;

	if (!ft_check_for_swap(a->m_head, b->m_head, a->name))
		return ;
	if (ft_check_for_swap(a->m_head, b->m_head, a->name) == 1)
	{
		ft_swap(a);
		ft_printf("s%c\n", a->name);
		return ;
	}
	if (ft_check_for_swap(a->m_head, b->m_head, a->name) == -1)
	{
		ft_swap(b);
		ft_printf("s%c\n", b->name);
		return ;
	}
	if (ft_check_for_swap(a->m_head, b->m_head, a->name) == 2)
	{
		ft_swap(a);
		ft_swap(b);
		ft_printf("ss\n");
	}
}
