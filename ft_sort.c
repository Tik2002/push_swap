/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:35:03 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/18 19:23:56 by tigpetro         ###   ########.fr       */
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
		// ft_printf("head = %d\n", head->data);
		if (l->data > r->data)
			return (1);
		l = l->next;
		r = r->next;
	}
	return (0);
}
