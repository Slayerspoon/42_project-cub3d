/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:12:17 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/08 17:34:37 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H "cub3d.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "./mlx/mlx.h"
# include "./libft/libft.h"

typedef struct s_gamedata
{
	void	*mlx;
	void	*win;
	char	map_layout[1000][1000];
	char	*map_nsew[4];
	int		map_floorcolor[3];
	int		map_ceilingcolor[3];
	void	**imgs;
	int		moves;
}	t_gamedata;

typedef struct s_resolution {
	int	x;
	int	y;
}	t_resolution;

/* main.c */
int		main(int argc, char **argv);
int		exit_game(t_gamedata *gamedata);

/* process_gamedata.c */
char	*read_to_string(int fd);
char	first_nonspace_char(char *line);
char	process_valid_line(char *line, t_gamedata *gamedata);
int		populate_gamedata(char *source, t_gamedata *gamedata);
int		process_gamedata(char *map_file_path, t_gamedata *gamedata);

/* process_nsew.c */
char	process_north(char *line, t_gamedata *gamedata);
char	process_south(char *line, t_gamedata *gamedata);
char	process_east(char *line, t_gamedata *gamedata);
char	process_west(char *line, t_gamedata *gamedata);

/* process_floor_ceiling.c */
int		go_to_next_colorcode(char *line, int start);
int		get_colorcode(char *start_ptr);
char	process_floor(char *line, t_gamedata *gamedata);
char	process_ceiling(char *line, t_gamedata *gamedata);

/* process_layout.c */
char	process_layout(char *start, t_gamedata *gamedata);

// char	**generate_game_map(int fd);
// char	**error_check_map(char *map_file_path);
// int	set_resolution(t_resolution *resolution, t_vars vars);
// void	**create_image_array(void *mlx);
// void	display_map(t_vars vars, void **imgs, char **map, char dolphin_facing);
// int	update_map(char **map, char movement);
// int	count_collectibles(char **map);

#endif
