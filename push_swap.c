/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:57 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/04 21:07:39 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	**push_swap(t_stack **a)
{
	return (a);
}

static int	err()
{
	printf("%s\n", "Error");
	return (1);
}

int	check(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if ((ft_strlen(av[i]) > 11) || (ft_arr_int(av[i]) == 2147483649))
		{
			return (err());
		}
		j = 1;
		while (j < i)
		{
			if (!ft_strncmp(av[j], av[i], ft_strlen(av[i])))
			{
				return (err());
			}
			j++;
		}
		i++;
	}
	return (0);
}
