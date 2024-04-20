/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:32:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/20 23:05:21 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

static int	ac_count(char **av)
{
	int	j;

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
		new_av[i] = ft_strdup(tmp[i - 1]);
	new_av[i] = 0;
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free (tmp);
	return (new_av);
}

static void	main_util(int ac, char **av, t_stack *a, t_stack *b)
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
	handle(a, b);
	if (ft_is_sorted(a->m_head))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}

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
		return (1);
	main_util(ac, av, &a, &b);
	return (0);
}
