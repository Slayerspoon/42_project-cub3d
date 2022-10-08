/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nsew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:09:49 by aionescu          #+#    #+#             */
/*   Updated: 2022/08/25 19:51:56 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	process_north(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_north;

	index = 0;
	while (line[index] != 'N')
		index++;
	if (line[index + 1] == 'O' && line[index + 2] == ' ')
	{
		index++;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_map_north = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[0][index_map_north] = line[index];
			index_map_north++;
			index++;
		}
	}
	else
		return ('n');
	return ('N');
}

char	process_south(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_south;

	index = 0;
	while (line[index] != 'S')
		index++;
	if (line[index + 1] == 'O' && line[index + 2] == ' ')
	{
		index++;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_map_south = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[1][index_map_south] = line[index];
			index_map_south++;
			index++;
		}
	}
	else
		return ('s');
	return ('S');
}

char	process_east(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_east;

	index = 0;
	while (line[index] != 'E')
		index++;
	if (line[index + 1] == 'A' && line[index + 2] == ' ')
	{
		index++;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_map_east = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[2][index_map_east] = line[index];
			index_map_east++;
			index++;
		}
	}
	else
		return ('e');
	return ('E');
}

char	process_west(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_map_west;

	index = 0;
	while (line[index] != 'W')
		index++;
	if (line[index + 1] == 'E' && line[index + 2] == ' ')
	{
		index++;
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_map_west = 0;
		while (line[index] != ' ' && line[index] != '\t' && line[index] != '\n')
		{
			gamedata->map_nsew[3][index_map_west] = line[index];
			index_map_west++;
			index++;
		}
	}
	else
		return ('w');
	return ('W');
}
