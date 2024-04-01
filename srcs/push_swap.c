/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/01 20:17:41 by tigpetro         ###   ########.fr       */
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

void	ft_push_swap(t_stack *a, t_stack *b)
{
	while (!ft_is_sorted(a->m_head, a->name))
	{
		if (ft_offset_sort(a->m_head, a->name) == 1 || ft_offset_sort(b->m_head, b->name) == 1)
			rotate(a, b);
		else if (ft_offset_sort(a->m_head, a->name) == -1)
			reverse_rotate(a, b);
		else if (check_3(a) || ft_check_for_swap(a->m_head) == 1)
			swap(a, b);
		else if (a->m_head != a->m_head->next)
			rotate_to_min(a, min_data(a->m_head), b);
	}
	while (b->m_head != 0)
		ft_push(b, a);
}
