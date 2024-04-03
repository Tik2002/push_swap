/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:35:03 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/03 19:11:29 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_is_sorted(t_node *const head)
{
	t_node	*l;
	t_node	*r;

	l = head;
	r = head->next;
	while (r != head)
	{
		if (l->data > r->data)
			return (0);
		l = l->next;
		r = r->next;
	}
	return (1);
}

static int	ft_sort_util(t_node *prev_head, t_node *next_head, int min)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (next_head->data != min)
	{
		next_head = next_head->next;
		i++;
	}
	while (prev_head->data != min)
	{
		prev_head = prev_head->prev;
		j++;
	}
	if (i > j)
		if (ft_is_sorted(prev_head))
			return (-1);
	if (i <= j)
		if (ft_is_sorted(next_head))
			return (1);
	return (0);
}

static int	ft_find_min(t_node *prev_head, t_node *next_head, int min)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (next_head->data != min)
	{
		next_head = next_head->next;
		i++;
	}
	while (prev_head->data != min)
	{
		prev_head = prev_head->prev;
		j++;
	}
	if (i > j)
		return (1);
	return (0);
}

int	ft_offset_sort(t_node *const head)
{
	t_node	*next_head;
	t_node	*prev_head;
	int		min;

	if (!head || head == head->next)
		return (0);
	next_head = head->next;
	prev_head = head->prev;
	min = min_data(head);
	if (head->data == min)
		return (0);
	return (ft_sort_util(prev_head, next_head, min));
}

void	rotate_to_min(t_stack *a, int min, t_stack *b)
{
	t_node	*next_head;
	t_node	*prev_head;
	int		flag;
	int		i;

	i = 0;
	next_head = a->m_head->next;
	prev_head = a->m_head->prev;
	flag = ft_find_min(prev_head, next_head, min);
	if (flag == 0)
		while (a->m_head->data != min)
			ft_rotate(a);
	else
		while (a->m_head->data != min)
			ft_reverse_rotate(a);
	ft_push(a, b);
}
