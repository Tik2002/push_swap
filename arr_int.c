/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:23:27 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/04 20:42:41 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long long	ft_arr_int(const char *str)
{
	int			i;
	int			negativ;
	long long	buff;

	i = 0;
	negativ = 1;
	buff = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				negativ = -negativ;
		}
		else if (!ft_isdigit(str[i]))
			return (2147483649);
		else
			buff = buff * 10 + (str[i] - '0');
		i++;
	}
	buff *= negativ;
	if (buff < INT_MIN || buff > INT_MAX)
		return (2147483649);
	return (buff);
}
