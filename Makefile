# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 22:40:57 by vmistry           #+#    #+#              #
#    Updated: 2026/01/20 23:30:49 by vmistry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a
CC = cc
CFLAGS := -Wall -Werror -Wextra
AR := ar -rcs
RM := rm -f
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a
SRCS := push_swap.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	mv $(LIBFT) $(NAME)
	$(AR) $@ $<

$(LIBFT): $(LIBFT_DIR)
	make all -C $<

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
