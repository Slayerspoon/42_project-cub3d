# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/23 19:30:15 by aionescu          #+#    #+#              #
#    Updated: 2022/10/19 20:52:38 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

SRC		=	main.c \
			file_structure_check.c \
			missing_info_check.c \
			layout_logic_check.c \
			parsing_utils.c \
			process_gamedata.c \
			process_nsew.c \
			process_floor_ceiling.c \
			process_layout.c \
			get_next_line.c \
		
CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror

LIBFT_DIR = libft/
LIBFT = libft.a
UNAME_S := $(shell uname -s)
MINILBX_DIR = mlx/
ifeq ($(UNAME_S), Darwin)
	MINILBX = libmlx.a
endif
ifeq ($(UNAME_S), Linux)
	MINILBX = libmlx_Linux.a
endif

$(NAME):
	$(MAKE) all -C $(LIBFT_DIR)
	$(MAKE) -C $(MINILBX_DIR)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT_DIR)$(LIBFT) $(MINILBX_DIR)$(MINILBX) \
		-L/usr/X11/include/../lib -lXext -lX11 -lm -lz -o $(NAME)

all: $(NAME)

clean:
	$(MAKE) clean -C $(MINILBX_DIR)
	$(MAKE) clean -C $(LIBFT_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re