/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:08:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/07 20:02:32 by tigpetro         ###   ########.fr       */
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

t_stack		*ft_emptystacknew(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->next = 0;
	return (new);
}

void	ft_pushfront(t_stack **head)
{
	t_stack	*tmp;

	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	(*head)->next = tmp;
}

void	ft_delone(t_stack *lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	del(lst->data);
	free(lst);
}

static void	_clear(t_stack **lst, void (*del)(int))
{
	if (!*lst)
		return ;
	_clear(&(*lst)->next, del);
	ft_delone(*lst, del);
	*lst = 0;
}

void	ft_clear(t_stack **lst, void (*del)(int))
{
	if (!lst || !del)
		return ;
	_clear(lst, del);
	lst = 0;
}
