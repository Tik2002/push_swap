/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:23:27 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/22 19:13:52 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static long long	_ft_arr_int_util(const char *str, long long buff,
	int negativ, int flag)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			negativ = -negativ;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
		{
			flag = 1;
			buff = buff * 10 + (str[i] - '0');
		}
		else
			return (2147483649);
		i++;
	}
	buff *= negativ;
	if (buff < INT_MIN || buff > INT_MAX || !flag)
		return (2147483649);
	return (buff);
}

long long	ft_arr_int(const char *str)
{
	int			negativ;
	long long	buff;
	int			flag;

	negativ = 1;
	buff = 0;
	flag = 0;
	return (_ft_arr_int_util(str, buff, negativ, flag));
}
