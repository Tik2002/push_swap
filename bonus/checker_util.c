/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 20:38:39 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/20 23:05:17 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	parce_rotate(t_stack *a, t_stack *b, char const *input)
{
	if (!ft_strncmp(input, "ra", ft_strlen(input) - 1))
		ft_rotate(a, 0);
	else if (!ft_strncmp(input, "rb", ft_strlen(input) - 1))
		ft_rotate(b, 0);
	else if (!ft_strncmp(input, "rra", ft_strlen(input) - 1))
		ft_reverse_rotate(a, 0);
	else if (!ft_strncmp(input, "rrb", ft_strlen(input) - 1))
		ft_reverse_rotate(b, 0);
	else if (!ft_strncmp(input, "rr", ft_strlen(input) - 1))
		rr(a, b, 0);
	else if (!ft_strncmp(input, "rrr", ft_strlen(input) - 1))
		rrr(a, b, 0);
}

void	parce_swap(t_stack *a, t_stack *b, char const *input)
{
	if (!ft_strncmp(input, "sa", ft_strlen(input) - 1))
		ft_swap(a, 0);
	else if (!ft_strncmp(input, "sb", ft_strlen(input) - 1))
		ft_swap(b, 0);
	else if (!ft_strncmp(input, "ss", ft_strlen(input) - 1))
		ss(a, b, 0);
}

void	parce(t_stack *a, t_stack *b, char const *input)
{
	if (!ft_strncmp(input, "pa", ft_strlen(input) - 1))
		ft_push(b, a, 0);
	else if (!ft_strncmp(input, "pb", ft_strlen(input) - 1))
		ft_push(a, b, 0);
	parce_rotate(a, b, input);
	parce_swap(a, b, input);
}

void	handle(t_stack *a, t_stack *b)
{
	char	*input;

	input = get_next_line(0);
	while (input)
	{
		parce(a, b, input);
		free(input);
		input = get_next_line(0);
	}
}
