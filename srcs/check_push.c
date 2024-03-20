/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:26:59 by senate            #+#    #+#             */
/*   Updated: 2024/03/20 20:22:39 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_push(t_stack *a, t_stack *b)
{
	// ft_printf("push checking\n");
	if (a->m_head == a->m_head->next)
		return (ft_rev_sorted(b->m_head));
	if (b->m_head == b->m_head->next)
		return (ft_is_sorted(a->m_head));
	return (ft_rev_sorted(b->m_head)
		&& ft_is_sorted(a->m_head));
}

void	do_push(t_stack *a, t_stack *b)
{
	if (!(b->m_head) || !check_push(a, b))
		ft_push(a, b);
	else if (check_push(a, b))
		ft_push(b, a);
}
