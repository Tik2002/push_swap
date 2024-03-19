/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:57 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/06 20:22:15 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	err(void)
{
	printf("%s\n", "Error");
	return (1);
}

static int	check_cmp(int i, int j)
{
	char	*s1;
	char	*s2;
	int		k;

	k = 1;
	s1 = ft_itoa(i);
	s2 = ft_itoa(j);
	if (ft_strlen(s1) == ft_strlen(s2))
		if (!ft_strncmp(s1, s2, max_len(ft_strlen(s1), ft_strlen(s2))))
			k = 0;
	free(s1);
	free(s2);
	return (k);
}

static char	*check_str(char *s, int i)
{
	int		j;
	char	*av;
	char	*tmp;

	av = ft_strdup(s);
	j = 0;
	if (av[j] == '-' || av[j] == '+')
		j++;
	while (av[j] == '0')
	{
		if (av[j + 1] == '\0')
			break ;
		j++;
	}
	if (i < 0)
	{
		j--;
		av[j] = '-';
	}
	tmp = ft_strdup(av + j);
	free(av);
	return (tmp);
}

static int	check_transform(int i, char *s)
{
	char	*tmp;
	char	*av;
	int		k;

	k = 1;
	av = check_str(s, i);
	tmp = ft_itoa(i);
	if (ft_strncmp(av, tmp, ft_strlen(tmp)))
		k = 0;
	free(tmp);
	free(av);
	return (k);
}

int	check(char **av, int ac)
{
	int			i;
	int			j;
	long long	*ptr;

	ptr = (long long *)malloc(sizeof(long long) * (ac - 1));
	if (!ptr)
		return (0);
	i = 1;
	while (av[i])
	{
		ptr[i - 1] = ft_arr_int(av[i]);
		if (ptr[i - 1] == 2147483649 || !check_transform(ptr[i - 1], av[i]))
			return (err());
		j = 0;
		while (j < i - 1)
			if (!check_cmp(ptr[i - 1], ptr[j++]))
				return (err());
		i++;
	}
	free(ptr);
	return (0);
}
