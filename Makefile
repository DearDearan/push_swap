# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lifranco <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 16:41:37 by lifranco          #+#    #+#              #
#    Updated: 2026/02/16 04:12:40 by lifranco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= push_swap
CC 		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iinclude -g
SRC = main.c \
	init_stack.c \
	butterfly.c \
	ft_atol.c \
	error_check.c \
	parsing.c \
	sort.c \
	stack_mod.c \
	ft_stacksize.c \

OBJ = $(SRC:.c=.o)
LIBFT_DIR = include/libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) clean -C $(LIBFT_DIR) 

fclean: clean
	rm -rf $(NAME)
	$(MAKE) fclean -C $(LIBFT_DIR)
re: fclean all

.PHONY: all clean fclean re

	
