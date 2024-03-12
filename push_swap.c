/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/12 19:30:13 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*push_swap(t_stack **a, t_stack **b, int ac)
{
	int		i;

	i = 0;
	while (i++ < ac)
	{
		printf("before swap a = %d\n", (*a)->m_head->data);
		// printf("before swap b = %d\n", (*b)->m_head->data);

		(*a)->m_head = (*a)->m_head->next;
	}
	// if ((*a)->m_head->data > (*a)->m_head->next->data)
	// 	ft_swap(a);
	// ft_rotate(a);
	// ft_rotate(a);
	ft_push_a(a, b);
	ft_push_a(a, b);
	i = 0;
	while (i++ < ac)
	{
		printf("after swap a = %d\n", (*a)->m_head->data);
		printf("after swap b = %d\n", (*b)->m_head->data);
		(*a)->m_head = (*a)->m_head->next;
		(*b)->m_head = (*b)->m_head->next;
	}

	return (0);
}
