/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unused.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:04:47 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/20 23:05:02 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	ss(t_stack *a, t_stack *b, int flag)
{
	ft_swap(a, 0);
	ft_swap(b, 0);
	if (flag)
		ft_printf("ss\n");
}

void	rr(t_stack *a, t_stack *b, int flag)
{
	ft_rotate(a, 0);
	ft_rotate(b, 0);
	if (flag)
		ft_printf("rr\n");
}

void	rrr(t_stack *a, t_stack *b, int flag)
{
	ft_reverse_rotate(a, 0);
	ft_reverse_rotate(b, 0);
	if (flag)
		ft_printf("rrr\n");
}
