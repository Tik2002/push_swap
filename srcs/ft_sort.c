/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:35:03 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/20 20:00:14 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_is_sorted(t_node *const head)
{
	t_node	*l;
	t_node	*r;

	l = head;
	r = head->next;
	while(r != head)
	{
		if (l->data > r->data)
			return (0);
		l = l->next;
		r = r->next;
	}
	return (1);
}

int	ft_rev_sorted(t_node *const head)
{
	t_node	*l;
	t_node	*r;

	l = head;
	r = head->next;
	while(r != head)
	{
		if (l->data < r->data)
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

static int	ft_rev_sort_util(t_node *prev_head, t_node *next_head, int max)
{
	int		i;
	int		j;

	i = 1;
	j = 1;
	while (next_head->data != max)
	{
		next_head = next_head->next;
		i++;
	}
	while (prev_head->data != max)
	{
		prev_head = prev_head->prev;
		j++;
	}
	if (i > j)
		if (ft_rev_sorted(prev_head))
			return (-1);
	if (i <= j)
		if (ft_rev_sorted(next_head))
			return (1);
	return (0);
}

int	ft_offset_sort(t_node *const head, int bool)
{
	t_node	*next_head;
	t_node	*prev_head;
	int		min;
	int		max;

	if (!head || head->prev == head->next)
		return (0);
	next_head = head->next;
	prev_head = head->prev;
	if (bool)
	{
		min = min_data(head);
		if (head->data == min)
			return (0);
		return (ft_sort_util(prev_head, next_head, min));
	}
	else
	{
		max = max_data(head);
		if (head->data == max)
			return (0);
		return (ft_rev_sort_util(prev_head, next_head, max));
	}
	return (0);
}
