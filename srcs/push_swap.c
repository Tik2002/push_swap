/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/20 21:30:16 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	check_sort(t_stack *a, t_stack *b)
{
	if (!(b->m_head))
		if (ft_is_sorted(a->m_head))
			return (0);
	return (1);
}

void	ft_push_swap(t_stack *a, t_stack *b)
{
	// int i = 0;
	while (check_sort(a, b))
	{
		if (check_rotate(a, b))
			do_rotate(a, b);
		else if (check_rev_rotate(a, b))
			do_rev_rotate(a, b);
		else if (check_swap(a, b))
			do_swap(a, b);
		else
			do_push(a, b);
		// i++;
	}
	// ft_printf("check %d\n", !(b->m_head));
	// print_stack(*a, *b);
	// ft_printf("%d\n", i);
}
