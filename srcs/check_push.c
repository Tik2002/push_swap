/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 23:26:59 by senate            #+#    #+#             */
/*   Updated: 2024/03/20 01:13:05 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	check_push(t_stack *a, t_stack *b)
{
	ft_printf("push checking\n");
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
