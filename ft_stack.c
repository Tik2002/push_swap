/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/10 18:20:12 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_stacknew(int n)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->data = n;
	new->next = 0;
	return (new);
}

void	ft_rotate(t_stack **head)
{
	*head = (*head)->next;
}

void	ft_rev_rotate(t_stack **head, t_stack **tail)
{
	while (*head != *tail)
		ft_rotate(head);
}

void	ft_swap(t_stack **head, t_stack **tail)
{
	t_stack	*tmp;
	t_stack	*tmp_next;

	if (!(*head) || !(*head)->next)
		return ;
	tmp = *head;
	tmp_next = (*head)->next;
	if ((*head)->next != (*tail))
	{
		*head = tmp_next;
		tmp->next = tmp_next->next;
		(*head)->next = tmp;
		(*tail)->next = *head;
	}
	else
		*head = *tail;
}

void	ft_pushfront(t_stack **lst, t_stack *new)
{
	void	*tmp;

	tmp = *lst;
	new->next = tmp;
	*lst = new;
}
