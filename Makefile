# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnaouss <mnaouss@student.42beirut.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/23 09:38:20 by mnaouss           #+#    #+#              #
#    Updated: 2025/07/23 10:07:58 by mnaouss          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -Ift_printf

# Project name
NAME = push_swap

# Source files
SRC = main.c utils.c ft_split.c sort.c operations.c
OBJ = $(SRC:.c=.o)

# ft_printf files
PRINTF_SRC = ft_printf/ft_printf.c ft_printf/print.c ft_printf/print_ptr.c
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJ) $(PRINTF_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_OBJ) -o $(NAME)

clean:
	rm -f $(OBJ) $(PRINTF_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
