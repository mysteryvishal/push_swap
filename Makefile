# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 22:40:57 by vmistry           #+#    #+#              #
#    Updated: 2026/03/06 08:45:36 by vmistry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS := -Wall -Werror -Wextra -Iinclude -Ilibft
RM := rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = src/main.c \
       src/parsing.c \
       src/operations/push.c \
       src/operations/rotate.c \
       src/operations/rev_rotate.c \
       src/operations/swap.c \
       src/sort/sort.c \
       src/sort/sort_small.c \
       src/sort/sort_large.c \
       src/sort/sort_large_utils.c \
       src/sort/sort_utils.c \
       src/utils.c

OBJS = $(SRCS:.c=.o)

BONUS_NAME  = checker
BONUS_SRCS  = bonus/checker_bonus.c \
              bonus/swap_bonus.c \
              bonus/push_bonus.c \
              bonus/rotate_bonus.c \
              bonus/rev_rotate_bonus.c \
              src/parsing.c \
              src/utils.c
BONUS_OBJS  = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(LIBFT): $(LIBFT_DIR)
bonus: $(LIBFT) $(BONUS_OBJS)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
