/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:12:17 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/15 19:12:14 by aionescu         ###   ########.fr       */
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
	char	map_layout[100][100];
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

/* parsing_utils.c */
char	first_nonspace_char(char *line);

/* file_structure_check.c */
int		check_element_beginning(char *l);
int		check_lines(char *lines_as_str);
int		file_structure_check(char *filename);

/* missing_info_check.c */
void	update_counters(char *line_start, int *counters);
int		missing_info_check(char *start);

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

#endif
