/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/19 20:03:36 by tigpetro         ###   ########.fr       */
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
void		print_stack(t_stack stack, int ac);

// main
int			main(int ac, char **av);
void		push_swap(t_stack *a, t_stack *b, int ac);

// a_sort
void		ra(t_stack *a, int flag);
void		rra(t_stack *a, int flag);
void		sa(t_stack *a, int flag);

// b_sort
void		rb(t_stack *b, int flag);
void		rrb(t_stack *b, int flag);
void		sb(t_stack *b, int flag);

// stack
void		rr(t_stack *a, t_stack *b);
void		rrr(t_stack *a, t_stack *b);
void		ss(t_stack *a, t_stack *b);
void		ft_push(t_stack *from, t_stack *to);
void		pushfront(int n, t_stack *stack);

// new_stack
t_stack		*ft_new_stack(void);
t_node		*ft_new_node(int n);
void		pushback(int n, t_stack *stack);
int			min_data(t_node *const head);
int			max_data(t_node *const head);

// sort
int			ft_is_sorted(t_node *const head);
int			ft_rev_sorted(t_node *const head);
int			ft_offset_sort(t_node *const head, int bool);

// check
int			check(char **av, int ac);
long long	ft_arr_int(const char *str);
size_t		max_len(size_t i, size_t j);
int			err();

#endif //PUSH_SWAP_H
