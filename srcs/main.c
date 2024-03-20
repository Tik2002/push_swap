/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:16:53 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/20 21:29:58 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ac_count(char **av)
{
	int j;

	j = 0;
	while (av[j])
		j++;
	return (j);
}

static char	**make_split(char **av)
{
	char	**tmp;
	char	**new_av;
	int		i;

	i = 0;
	tmp = ft_split(av[1], ' ');
	new_av = (char **)malloc((ac_count(tmp) + 2) * sizeof(char *));
	if (!new_av)
		return (0);
	new_av[0] = ft_strdup(av[0]);
	while (tmp[i++])
		new_av[i] = strdup(tmp[i - 1]);
	new_av[i] = 0;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free (tmp);
	return (new_av);
}

static void	esh(int ac, char **av, t_stack *a, t_stack *b)
{
	int		i;

	if (check(av, ac))
		return ;
	i = 1;
	a = ft_new_stack();
	a->name = 'a';
	b = ft_new_stack();
	b->name = 'b';
	while (i < ac)
		ft_pushback(ft_arr_int(av[i++]), a);
	// print_stack(*a, *b);
	ft_push_swap(a, b);
}

// void	print_stack(t_stack a, t_stack b)
// {
// 	t_node *tmp_a;

// 	tmp_a = a.m_head;
// 	ft_printf("%d		", tmp_a->data);

// 	ft_printf("\n");
// 	tmp_a = tmp_a->next;
// 	while (tmp_a != a.m_head)
// 	{
// 		ft_printf("%d	", tmp_a->data);
// 		tmp_a = tmp_a->next;
// 		ft_printf("\n");
// 	}
// 	ft_printf("_		_\n%c		%c\n", a.name, b.name);
// }

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	if (ac == 2)
	{
		if (!av[1])
			return (err());
		av = make_split(av);
		ac = ac_count(av);
	}
	if (ac == 1)
		return (err());
	esh(ac, av, &a, &b);
	// system("leaks a.out");
	return (0);
}
