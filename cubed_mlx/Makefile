# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:30:15 by aionescu          #+#    #+#              #
#    Updated: 2022/11/11 19:49:39 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC		=	main.c \
			extra_checks.c \
			file_structure_check.c \
			init_and_render_img.c \
			keyboard.c \
			layout_logic_check.c \
			missing_info_check.c \
			parsing_utils.c \
			process_gamedata.c \
			process_nsew.c \
			process_floor_ceiling.c \
			process_layout.c \
			player_movement.c \
			parse_and_report.c \
			render_floor_ceiling.c \
			raycast.c \
			final_map.c
		
CC		=	gcc
CFLAGS_LINUX= -Wall -Wextra -Werror mlx/libmlx.a -lXext -lX11 -lm -lz -o
CFLAGS_MAC= -Wall -Wextra -Werror mlx/libmlx.a /usr/X11/lib/libXext.dylib /usr/X11/lib/libX11.dylib -lm -lz -o

LIBFT_DIR = libft/
LIBFT = libft/libft.a

MINILBX_DIR = ./mlx

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Darwin)
CFLAGS= $(CFLAGS_MAC)
else
CFLAGS= $(CFLAGS_LINUX)
endif

$(NAME):
	$(MAKE) all -C $(LIBFT_DIR)
	$(MAKE) all -C $(MINILBX_DIR)
	$(CC) $(SRC) $(LIBFT) $(CFLAGS) $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C $(MINILBX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

# test: $(NAME)
# 	./cub3d maps/mandatory.cub

# test1: $(NAME)
# 	./cub3d maps/test_inputfile.ber

# test2: $(NAME)
# 	./cub3d maps/test_inputfile.cub

# test2: $(NAME)
# 	./cub3d maps/test_file_invalid.cub

.PHONY: all clean fclean re