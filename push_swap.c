/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/07 20:02:05 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*push_swap(t_stack **a, t_stack **b, int ac)
{
	int i;
	int	j;

	j = 0;
	while (j++ != ac)
	{
		i = 0;
		while (i++ != ac - 1)
		{
			if ((*a)->data > (*a)->next->data)
				ft_pushfront(a);
			*a = (*a)->next;
		}
		*a = (*a)->next;
	}
	i = 0;
	while (i++ < 3)
	{
		printf("after swap %d  \n", (*a)->data);
		// printf("%d\n", (*b)->data);
		*a = (*a)->next;
		*b = (*b)->next;
	}
	return (0);
}
