/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/20 01:44:34 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_sort(t_stack *a, t_stack *b)
{
	if (ft_is_sorted(a->m_head) && !(b->m_head))
		return (0);
	return (1);
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	int i = 0;
	while (i++ < 15 && check_sort(a, b))
	{
		if (check_swap(a, b))
			do_swap(a, b);
		else if (check_rotate(a, b))
			do_rotate(a, b);
		else if (check_rev_rotate(a, b))
			do_rev_rotate(a, b);
		else
			do_push(a, b);
		// print_stack(*a, 5);
		// if (b->m_head)
		// 	print_stack(*b, 5);
		// ft_printf("final check\n");
	}
	ft_printf("check %d\n", !(b->m_head));
	print_stack(*a, 5);
}
