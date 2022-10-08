# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:30:15 by aionescu          #+#    #+#              #
#    Updated: 2022/08/23 19:30:22 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

LIBFT = libft.a

LIBMLX = libmlx.a

SRC = main.c error_check_map.c generate_game_map.c graphics_config.c \
		display_map.c update_map.c

OBJ = main.o error_check_map.o generate_game_map.o graphics_config.c \
		display_map.o update_map.o

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(LIBMLX) 
	$(CC) $(OBJ) $(LIBFT) $(LIBMLX) -L/usr/X11/lib -lXext -lX11 -g -o $(NAME)
	chmod a+x $(NAME)

$(OBJ): $(SRC)
	$(CC) -Wall -Wextra -Werror -Imlx -c $(SRC)

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
