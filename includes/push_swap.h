/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/22 21:32:40 by tigpetro         ###   ########.fr       */
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

// print
// void		print_stack(t_stack a, t_stack b);

// main
int			main(int ac, char **av);
void		ft_push_swap(t_stack *a, t_stack *b);

// stack_sorting
void		ft_rotate(t_stack *stack);
void		ft_reverse_rotate(t_stack *stack);
void		ft_swap(t_stack *stack);
void		ft_push(t_stack *from, t_stack *to);
void		ft_pushfront(int n, t_stack *stack);

// new_stack
t_stack		*ft_new_stack(void);
t_node		*ft_new_node(int n);
void		ft_pushback(int n, t_stack *stack);
int			min_data(t_node *const head);
int			max_data(t_node *const head);

// sort
int			ft_is_sorted(t_node *const head);
int			ft_offset_sort(t_node *const head);
void		rotate_to_min(t_stack *a, int min, t_stack *b);

// check
int			check(char **av, int ac);
long long	ft_arr_int(const char *str);
size_t		max_len(size_t i, size_t j);
int			err(void);

#endif //PUSH_SWAP_H
