##
## Makefile for Makefile in /home/borel_b//proj/minitalk/minitalk
## 
## Made by gregoire1 borel
## Login   <borel_b@epitech.net>
## 
## Started on  Thu Mar 17 15:16:18 2011 gregoire1 borel
## Last update Thu Mar 17 15:31:23 2011 gregoire1 borel
##

NAME_CLIENT=		client

NAME_SERVER=		server

SRC_CLIENT=		sources/client.c \
			sources/dec_to_bin.c \
			sources/str_functions.c \
			sources/aff_functions.c \
			sources/pong.c \
			sources/x_functions.c

SRC_SERVER=		sources/server.c \
			sources/my_atoi_base.c \
			sources/aff_functions.c

OBJ_CLIENT=		$(SRC_CLIENT:.c=.o)

OBJ_SERVER=		$(SRC_SERVER:.c=.o)

CC=			gcc

CFLAGS	+=		-W -Wall -Wextra -ansi -pedantic

do:
			@make $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER):		$(OBJ_SERVER)
			$(CC) -o $(NAME_SERVER) $(OBJ_SERVER) $(CFLAGS)

$(NAME_CLIENT):		$(OBJ_CLIENT)
			$(CC) -o $(NAME_CLIENT) $(OBJ_CLIENT) $(CFLAGS)

all:			$(NAME_SERVER) $(NAME_CLIENT)

clean:
			rm -f $(OBJ_SERVER) $(OBJ_CLIENT)
			rm -f *~ sources/*~ headers/*~

fclean:			clean
			rm -f $(NAME_CLIENT) $(NAME_SERVER)

re:			fclean all
