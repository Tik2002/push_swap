/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:16:53 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/10 18:21:28 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	int		i;
	t_stack	*a;
	t_stack *head;
	t_stack *tail;

	if (ac == 1)
		return (err());
	i = 1;
	if (check(av, ac))
		return (0);
	a = ft_stacknew(ft_arr_int(av[i++]));
	head = a;
	while (i < ac)
	{
		a->next = ft_stacknew(ft_arr_int(av[i++]));
		a = a->next;
	}
	tail = a;
	tail->next = head;
	push_swap(&head, &tail, ac);
	system("leaks a.out");
	return (0);
}
