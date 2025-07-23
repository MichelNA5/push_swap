CC      = cc
CFLAGS  = -Wall -Wextra -Werror

SRCS    = ft_printf.c print.c print_ptr.c
OBJS    = $(SRCS:.c=.o)
NAME    = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
