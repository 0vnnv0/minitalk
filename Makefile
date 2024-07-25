# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anschmit <anschmit@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 16:03:31 by anschmit          #+#    #+#              #
#    Updated: 2024/07/02 12:50:56 by anschmit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

CC = cc

CFLAGS = -Wall -Wextra -Werror -I/home/anschmit/done/libft

SRCS = client.c server.c

OBJS = $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME):	server client

server:	server.o
		make -C /home/anschmit/done/libft
		$(CC) $(CFLAGS) server.o -o server -L/home/anschmit/done/libft -l:libft.a

client:	client.o
		make -C /home/anschmit/done/libft
		$(CC) $(CFLAGS) client.o -o client -L/home/anschmit/done/libft -l:libft.a

libft: make -C /home/anschmit/done/libft

clean:
		make clean -C /home/anschmit/done/libft
		$(RM) $(OBJS) client server

fclean: clean
		rm -f lift/libft.a

re:	fclean all