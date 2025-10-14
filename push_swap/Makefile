NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

# если подключишь свою libft/ft_printf — раскомментируй строки ниже
# LIBFT_DIR := ./libft
# LIBFT_A   := $(LIBFT_DIR)/libft.a
# LFLAGS    := -L$(LIBFT_DIR) -lft
# IFLAGS    := -I$(LIBFT_DIR) -I.

SRCS := \
main.c \
stack_init.c \
stack_core.c \
ops_swap.c \
ops_push.c \
ops_rotate.c \
ops_revrotate.c \
print_ops.c \
args_parse.c

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) # $(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) # $(LFLAGS)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -I. -c $< -o $@

# Если используешь libft — добавь цели сборки:
# $(LIBFT_A):
# 	$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	# [опционально] $(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	# [опционально] $(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
