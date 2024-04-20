NAME = push_swap
BONUS_NAME = checker
MAIN = ./main/main.c
SRCSPATH = ./srcs/
BONUSPATH = ./bonus/
PRINTF_PATH = ./printf/
LIBFTPATH = ./libft/
INCPATH = ./includes/ ./printf/includes/ ./printf/libft/
SRCS = $(wildcard $(SRCSPATH)*.c)
OBJS = $(patsubst $(SRCSPATH)%.c,$(SRCSPATH)%.o,$(SRCS))
MAIN_OBJ = $(MAIN:.c=.o)
BONUS = $(wildcard $(BONUSPATH)*.c)
BONUS_OBJS = $(patsubst $(BONUSPATH)%.c,$(BONUSPATH)%.o,$(BONUS))
PRINTF = $(PRINTF_PATH)/srcs/*.o
LIBFT = $(LIBFTPATH)*.o

CC = cc
CFLAGS = -Wall -Wextra -Werror -c $(foreach H,$(INCPATH),-I$(H))

all : $(NAME)

$(NAME) : $(LIBFT) $(PRINTF) $(OBJS) $(MAIN_OBJ)
	$(CC) $(LIBFT) $(PRINTF) $(OBJS) $(MAIN_OBJ) -o $(NAME)

$(LIBFT) :
	make -C $(LIBFTPATH) all

$(PRINTF) :
	make -C $(PRINTF_PATH) all

$(SRCSPATH)%.o : $(SRCSPATH)%.c
	$(CC) $(CFLAGS) $< -o $@

$(MAIN_OBJ) : $(MAIN)
	$(CC) $(CFLAGS) $< -o $@

bonus : $(BONUS_NAME)

$(BONUS_NAME) : $(LIBFT) $(PRINTF) $(OBJS) $(BONUS_OBJS)
	$(CC) $(LIBFT) $(PRINTF) $(OBJS) $(BONUS_OBJS) -o $(BONUS_NAME)

$(BONUSPATH)%.o : $(BONUSPATH)%.c
	$(CC) $(CFLAGS) $< -o $@

clean :
	make -C $(PRINTF_PATH) clean
	make -C $(LIBFTPATH) clean
	rm -f $(MAIN_OBJ)
	rm -f $(BONUS_OBJS)
	rm -f $(OBJS)

fclean : clean
	make -C $(PRINTF_PATH) fclean
	make -C $(LIBFTPATH) fclean
	rm -f $(MAIN_OBJ)
	rm -f $(BONUS_NAME)
	rm -f $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re
