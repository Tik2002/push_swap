/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/10 18:20:27 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

// main
int			main(int ac, char **av);

//stack
t_stack		*ft_stacknew(int n);
void		ft_swap(t_stack **head, t_stack **tail);
void		ft_rotate(t_stack **head);
void		ft_rev_rotate(t_stack **head, t_stack **tail);
void		ft_pushfront(t_stack **lst, t_stack *new);

char		*push_swap(t_stack **head, t_stack **tail, int ac);

// check
int			check(char **av, int ac);
long long	ft_arr_int(const char *str);
size_t		max_len(size_t i, size_t j);
int			err();

#endif //PUSH_SWAP_H
