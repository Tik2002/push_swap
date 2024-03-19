/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 19:23:27 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/05 20:57:24 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

long long	ft_arr_int(const char *str)
{
	int			i;
	int			negativ;
	long long	buff;
	int			flag;

	i = 0;
	negativ = 1;
	buff = 0;
	flag = 0;
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
