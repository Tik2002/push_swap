/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 20:13:00 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/10 18:15:22 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

char	*push_swap(t_stack **head, t_stack **tail, int ac)
{
	int i;

	i = 0;
	while (i++ < ac - 1)
	{
		printf("before swap %d\n", (*head)->data);
		*head = (*head)->next;
	}
	if ((*head)->data > (*head)->next->data)
		ft_swap(head, tail);
	i = 0;
	while (i++ < ac)
	{
		printf("after swap %d\n", (*head)->data);
		*head = (*head)->next;
	}

	return (0);
}
