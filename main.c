/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:16:53 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/06 21:02:14 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	int		i;
	t_stack	*tmp_a;
	t_stack *head;
	// t_stack *tmp_b;

	if (ac == 1)
		return (err());
	i = 1;
	if (check(av, ac))
		return (0);
	tmp_a = ft_stacknew(ft_arr_int(av[i++]));
	head = tmp_a;
	// tmp_b = (ft_stacknew(ac));
	while (i < ac)
	{
		tmp_a->next = ft_stacknew(ft_arr_int(av[i++]));
		tmp_a = tmp_a->next;
	}
	tmp_a->next = head;
	push_swap(&head);
	system("leaks a.out");
	return (0);
}
