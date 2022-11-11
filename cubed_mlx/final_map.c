/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:45:55 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/11 21:36:32 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function returns a special char to describe the player's facing
// based on the specific character in the initial map.
// In the final version of the map, there are a total of 8 directions:
// a for N, c for E, e for S, g for W,
// b for NE, d for SE, f for SW, h for NW
char	init_face(char nsew)
{
	if (nsew == 'N')
		return ('a');
	else if (nsew == 'E')
		return ('c');
	else if (nsew == 'S')
		return ('e');
	else
		return ('g');
}

// This function generates a square of '0's in the final map, but with one
// special char in the center describing the position and facing of the player.
void	generate_p_square(char **final_map, t_gamedata *gamedata, int x, int y)
{
	int	row;
	int	col;
	int	factor;

	factor = 5;
	row = y * factor;
	col = x * factor;
	while (row < y * factor + factor)
	{
		while (col < x * factor + factor)
		{
			if (col == x * factor + factor / 2
				&& row == y * factor + factor / 2)
				final_map[row][col] = init_face(gamedata->map_layout[y][x]);
			else
				final_map[row][col] = '0';
			col++;
		}
		col = x * factor;
		row++;
	}
}

// This function generates a square in the final map
// formed out of the char from the initial map at that position.
void	generate_square(char **final_map, t_gamedata *gamedata, int x, int y)
{
	int	row;
	int	col;
	int	factor;

	factor = 5;
	row = y * factor;
	col = x * factor;
	while (row < y * factor + factor)
	{
		while (col < x * factor + factor)
		{
			final_map[row][col] = gamedata->map_layout[y][x];
			col++;
		}
		col = x * factor;
		row++;
	}
}

// This function calculates the exact number of bytes necessary
// for the final map and allocates and assembles it in a **char
char	**allocate_final_map(t_gamedata *gamedata, int factor)
{
	char	**allocated_map;
	int		x;
	int		y;
	int		side_size;

	x = 0;
	y = 0;
	while (gamedata->map_layout[0][x] != '\0')
		x++;
	while (gamedata->map_layout[y][0] != '\0')
		y++;
	side_size = y * factor;
	allocated_map = ft_calloc(y * factor + 1, sizeof(char *));
	y = 0;
	while (y < side_size)
	{
		allocated_map[y] = ft_calloc(x * factor + 1, sizeof(char));
		y++;
	}
	allocated_map[y] = ft_calloc(x * factor + 1, sizeof(char));
	return (allocated_map);
}

// This chain of functions allocates memory efficiently for a version
// of the initial map that has a hard-coded higher "resolution" (now 5x5)
// for every character in the initially processed map.
char	**generate_final_map(t_gamedata *gamedata)
{
	char	**final_map;
	int		x;
	int		y;

	final_map = allocate_final_map(gamedata, 5);
	x = 0;
	y = 0;
	while (gamedata->map_layout[y][x] != '\0')
	{
		while (gamedata->map_layout[y][x] != '\0')
		{
			if (gamedata->map_layout[y][x] == 'N'
				|| gamedata->map_layout[y][x] == 'S'
				|| gamedata->map_layout[y][x] == 'E'
				|| gamedata->map_layout[y][x] == 'W')
				generate_p_square(final_map, gamedata, x, y);
			else
				generate_square(final_map, gamedata, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (final_map);
}
