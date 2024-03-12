NAME = push_swap
SRCSPATH = ./
LIBFTPATH = ./libft/
INCPATH = ./ ./libft/

SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))
LIBFT = $(LIBFTPATH)*.o

CC = cc
CFLAGS = -Wall -Wextra -c $(foreach H,$(INCPATH),-I$(H))
 #-Werror
all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS)
	ar -rcs $(NAME) $(LIBFT) $(OBJS)

$(LIBFT) :
	make -C $(LIBFTPATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS)  $< -o $@

clean :
	make -C $(LIBFTPATH) clean
	rm -f $(OBJS)

fclean : clean
	make -C $(LIBFTPATH) fclean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
