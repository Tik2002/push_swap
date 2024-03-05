/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/05 21:37:10 by tigpetro         ###   ########.fr       */
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
t_stack		**push_swap(t_stack **a);
void		ft_clear(t_stack **lst, void (*del)(int));
void		ft_delone(t_stack *lst, void (*del)(int));
t_stack		*ft_stacknew(int n);
void		ft_pushfront(t_stack **lst, t_stack *new);

// check
int			check(char **av, int ac);
long long	ft_arr_int(const char *str);
size_t		max_len(size_t i, size_t j);
int			err();

#endif //PUSH_SWAP_H
