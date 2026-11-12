NAME        = push_swap
BONUS_NAME  = checker

LIBFTDIR    = ./libft
LIBFTNAME   = libft.a

CC          = cc
CFLAGS      = -Wall -Werror -Wextra

HEADERS     = ./include

SRC_COMMON = \
	./src/ft_array.c \
	./src/ft_cheapest.c \
	./src/ft_exec.c \
	./src/free.c \
	./src/ft_sort0.c \
	./src/parsing.c \
	./src/ft_rot_ops.c \
	./src/ft_sort.c \
	./src/push.c \
	./src/rotate.c \
	./src/rrotate.c \
	./src/stack_init.c \
	./src/swap.c \
	./src/utils.c \
	./src/ft_utils.c

SRC_PUSH_SWAP = \
	./src/push_swap.c

SRC_CHECKER = \
	./bonus/checker.c

OBJS_COMMON     = $(SRC_COMMON:.c=.o)
OBJS_PUSH_SWAP = $(SRC_PUSH_SWAP:.c=.o)
OBJS_CHECKER   = $(SRC_CHECKER:.c=.o)

all: $(NAME)

$(NAME): $(OBJS_COMMON) $(OBJS_PUSH_SWAP)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -I$(HEADERS) -o $(NAME) \
		$(OBJS_COMMON) $(OBJS_PUSH_SWAP) -L $(LIBFTDIR) -lft

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(OBJS_COMMON) $(OBJS_CHECKER)
	@make -C $(LIBFTDIR)
	@$(CC) $(CFLAGS) -I$(HEADERS) -o $(BONUS_NAME) \
		$(OBJS_COMMON) $(OBJS_CHECKER) -L $(LIBFTDIR) -lft

clean:
	@make -C $(LIBFTDIR) clean
	@rm -f $(OBJS_COMMON) $(OBJS_PUSH_SWAP) $(OBJS_CHECKER)

fclean: clean
	@make -C $(LIBFTDIR) fclean
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
