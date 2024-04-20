/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:02:40 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/20 23:07:49 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# define BUFFER_SIZE 4

# include <push_swap.h>

// GNEL_DZYA
char	*gnl_strchr(char *s, int c);
void	gnl_strjoin(char **line, char *buff);
void	gnl_new_line(char **line, char *next_lines);
char	*gnl_strdup(char **line);
void	gnl_read(int fd, char **line);
char	*get_next_line(int fd);

// unused
void	ss(t_stack *a, t_stack *b, int flag);
void	rr(t_stack *a, t_stack *b, int flag);
void	rrr(t_stack *a, t_stack *b, int flag);

// checker_utils
void	handle(t_stack *a, t_stack *b);
void	parce(t_stack *a, t_stack *b, char const *input);
void	parce_swap(t_stack *a, t_stack *b, char const *input);
void	parce_rotate(t_stack *a, t_stack *b, char const *input);

#endif //CHECKER_H
