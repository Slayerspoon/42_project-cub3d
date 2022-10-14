# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:30:15 by aionescu          #+#    #+#              #
#    Updated: 2022/10/12 19:13:59 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft.a

LIBMLX = libmlx.a

SRC = main.c process_gamedata.c process_nsew.c process_floor_ceiling.c \
		process_layout.c

# OBJ = main.o process_gamedata.o process_nsew.o process_floor_ceiling.o \
# 		process_layout.o

all: $(NAME)

# $(NAME): $(OBJ) $(LIBFT) $(LIBMLX) 
# 	$(CC) $(OBJ) $(LIBFT) $(LIBMLX) -L/usr/X11/lib -lXext -lX11 -g -o $(NAME)
# 	chmod a+x $(NAME)

$(NAME): $(LIBFT)
	$(CC) -Wall -Wextra -Werror $(SRC) $(LIBFT) -o $(NAME)
	rm -f *.o
	chmod a+x $(NAME)

# $(OBJ): $(SRC)
# 	$(CC) -Wall -Wextra -Werror -Imlx -c $(SRC)

$(LIBFT):
	cd libft && $(MAKE)
	mv libft/libft.a libft.a

$(LIBMLX):
	cd mlx && $(MAKE)
	mv mlx/libmlx.a libmlx.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
