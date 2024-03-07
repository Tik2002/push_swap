/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:16:53 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/07 19:46:04 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	int		i;
	t_stack	*tmp_a;
	t_stack *head_a;
	t_stack *tmp_b;
	t_stack *head_b;

	if (ac == 1)
		return (err());
	i = 1;
	if (check(av, ac))
		return (0);
	tmp_a = ft_stacknew(ft_arr_int(av[i++]));
	head_a = tmp_a;
	tmp_b = ft_emptystacknew();
	head_b = tmp_b;
	while (i < ac)
	{
		tmp_a->next = ft_stacknew(ft_arr_int(av[i++]));
		tmp_b->next = ft_emptystacknew();
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
	tmp_a->next = head_a;
	tmp_b->next = head_b;
	push_swap(&head_a, &head_b, ac);
	system("leaks a.out");
	return (0);
}
