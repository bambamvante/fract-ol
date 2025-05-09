# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: baebae <baebae@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/16 15:48:38 by arphueng          #+#    #+#              #
#    Updated: 2025/03/25 22:04:01 by baebae           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printc_p.c ft_printhex.c ft_printf.c \
	ft_printint.c ft_printptr.c ft_printstr.c ft_printuint.c 
AR = ar -rcs
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MKDIR = mkdir -p

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re