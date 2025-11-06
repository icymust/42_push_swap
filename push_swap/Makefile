NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

SRCS := \
main.c \
stack_init.c stack_core.c \
ops_swap.c ops_push.c ops_rotate.c ops_revrotate.c \
args_parse.c parse_utils.c index.c \
sort_small.c sort_big_chunks.c sort_utils.c \

OBJS := $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
