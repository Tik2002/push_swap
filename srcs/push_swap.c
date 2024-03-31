/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/22 21:36:10 by tigpetro         ###   ########.fr       */
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

static int	ft_check_for_swap(t_node *const head)
{
	if (head->data > head->next->data && ft_till_sorted(head->next->next, head))
		return (1);
	else if (head->prev->prev->data > head->prev->data
		&& ft_till_sorted(head, head->prev->prev))
		return (-1);
	return (0);
}

static void	rr_rr_s(t_stack *a)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(a);
	ft_swap(a);
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
		else if (ft_check_for_swap(a->m_head) == -1)
			rr_rr_s(a);
		else if (a->m_head != a->m_head->next)
			rotate_to_min(a, min_data(a->m_head), b);
	}
	while (b->m_head != 0)
		ft_push(b, a);
}
