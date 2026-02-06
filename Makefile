# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmuler-f <lmuler-f@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/05 13:46:14 by lmuler-f          #+#    #+#              #
#    Updated: 2026/02/05 13:46:14 by lmuler-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDE_DIR = includes
INCLUDES = -I$(INCLUDE_DIR) -I$(LIBFT_DIR)


SRC = src/operations/push.c \
	src/operations/swap.c \
	src/operations/rotate.c \
	src/operations/reverse_rotate.c \
	src/parsing/fill_stack.c \
	src/parsing/parsing_args.c \
	src/parsing/parsing_stack.c \
	src/parsing/parsing_utils.c \
	src/parsing/index_stack.c \
	src/sorting/best_move.c \
	src/sorting/sort.c \
	src/sorting/cost.c \
	src/sorting/position.c \
	src/utils/free_stack.c \
	src/utils/free_arr.c \
	src/utils/lists.c \
	push_swap.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(RM) $(OBJ)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re