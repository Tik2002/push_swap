/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:35:03 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 15:43:56 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_not_sorted(t_node  *const head)
{
	t_node	*l;
	t_node	*r;

	l = head;
	r = head->next;
	while(r != head)
	{
		if (l->data > r->data)
			return (1);
		l = l->next;
		r = r->next;
	}
	return (0);
}
