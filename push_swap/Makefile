# Makefile
NAME    := push_swap
CC      := cc
CFLAGS  := -Wall -Wextra -Werror

SRC     := main.c stack.c
OBJ     := $(SRC:.c=.o)
INC     := -I .

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

test: $(NAME)
	./$(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
