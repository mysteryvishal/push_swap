# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmistry <vmistry@student.42london.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/20 22:40:57 by vmistry           #+#    #+#              #
#    Updated: 2026/01/20 22:43:09 by vmistry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS := -Wall -Werror -Wextra
AR := ar -rcs
RM := rm -f
SRCS := push_swap.c
OBJS = $(SRCS:.c=.o)

all:

$(NAME):

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
