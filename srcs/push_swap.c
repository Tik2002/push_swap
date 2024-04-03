/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/03 19:22:27 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_3(t_stack *a)
{
	if (a->m_head->next->next == a->m_head->prev)
		return (1);
	return (0);
}

static int	ft_till_sorted(t_node *const head, t_node *const last)
{
	t_node	*l;
	t_node	*r;

	l = head;
	r = head->next;
	while (r != last)
	{
		if (l->data > r->data)
			return (0);
		l = l->next;
		r = r->next;
	}
	return (1);
}

static int	ft_check_for_swap(t_node *const head_a)
{
	if (head_a->data > head_a->next->data && ft_till_sorted(head_a->next->next, head_a))
		return (1);
	return (0);
}
void	ft_push_swap(t_stack *a, t_stack *b)
{
	while (!ft_is_sorted(a->m_head))
	{
		if (ft_offset_sort(a->m_head) == 1)
			ft_rotate(a);
		else if (ft_offset_sort(a->m_head) == -1)
			ft_reverse_rotate(a);
		else if (check_3(a) || ft_check_for_swap(a->m_head) == 1)
			ft_swap(a);
		else if (a->m_head != a->m_head->next)
			rotate_to_min(a, min_data(a->m_head), b);
	}
	while (b->m_head != 0)
		ft_push(b, a);
}
