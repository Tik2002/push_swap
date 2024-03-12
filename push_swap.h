/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:59:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/03/12 19:27:19 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*m_head;
	t_node	*m_tail;
}	t_stack;

// main
int			main(int ac, char **av);
char		*push_swap(t_stack **head, t_stack **tail, int ac);

// stack
void		ft_rotate(t_stack **head);
void		ft_rev_rotate(t_stack **stack);
void		ft_push_a(t_stack **a, t_stack **b);
void		pushfront(int n, t_stack *stack);
void		ft_swap(t_stack **stack);

// new_stack
t_stack		*ft_new_stack(void);
t_node		*ft_new_node(int n);
void		pushback(int n, t_stack *stack);


// check
int			check(char **av, int ac);
long long	ft_arr_int(const char *str);
size_t		max_len(size_t i, size_t j);
int			err();

#endif //PUSH_SWAP_H
