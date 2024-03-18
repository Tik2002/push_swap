/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/18 19:32:39 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*m_head;
	char	name;
}	t_stack;

// jnjel
void		print_stack(t_stack *stack, int ac);

// main
int			main(int ac, char **av);
void		push_swap(t_stack **head, t_stack **tail, int ac);

// stack
void		ft_rotate(t_stack **head);
void		ft_rev_rotate(t_stack **stack);
void		ft_push(t_stack **from, t_stack **to);
void		pushfront(int n, t_stack *stack);
void		ft_swap(t_stack **stack);

// new_stack
t_stack		*ft_new_stack(void);
t_node		*ft_new_node(int n);
void		pushback(int n, t_stack *stack);

// sort
int			ft_not_sorted(t_node  *const head);

// check
int			check(char **av, int ac);
long long	ft_arr_int(const char *str);
size_t		max_len(size_t i, size_t j);
int			err();

#endif //PUSH_SWAP_H
