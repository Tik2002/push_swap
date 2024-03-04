/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:16:53 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/04 21:04:03 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int ac, char **av)
{
	int		i;
	t_stack	*tmp_a;
	// t_stack *tmp_b;

	i = 1;
	if (check(av))
		return (0);
	tmp_a = (ft_stacknew(ac));
	// tmp_b = (ft_stacknew(ac));
	while (i < ac)
	{
		tmp_a->data = ft_arr_int(av[i++]);
		printf("%d\n", tmp_a->data);
		tmp_a->next = tmp_a;
	}
	tmp_a->next = 0;
	push_swap(&tmp_a);
	system("leaks a.out");
	return (0);
}
