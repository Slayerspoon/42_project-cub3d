/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_floor_ceiling.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 19:53:30 by aionescu          #+#    #+#             */
/*   Updated: 2022/08/26 17:51:54 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	go_to_next_colorcode(char *line, int start)
{
	int	index;

	index = start;
	while (ft_isdigit(line[index]))
		index++;
	while (line[index] != ',')
		index++;
	while (!ft_isdigit(line[index]))
		index++;
	return (index);
}

int	get_colorcode(char *start_ptr)
{
	char	code_as_chars[4];
	int		index;
	int		count;

	count = 0;
	index = 0;
	while (ft_isdigit(start_ptr[index]))
	{
		code_as_chars[count] = start_ptr[index];
		count++;
		index++;
		if (count > 4)
			break ;
	}
	if (ft_atoi(code_as_chars) > 255)
		return (255);
	else
		return (ft_atoi(code_as_chars));
}

char	process_floor(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_rgb;

	index = 0;
	while (line[index] != 'F')
		index++;
	if (line[index + 1] == ' ' || line[index + 1] == '\t')
	{
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_rgb = 0;
		while (index_rgb < 3)
		{
			gamedata->map_floorcolor[index_rgb] = get_colorcode(line + index);
			index_rgb++;
			index = go_to_next_colorcode(line, index);
		}
	}
	else
		return ('f');
	return ('F');
}

char	process_ceiling(char *line, t_gamedata *gamedata)
{
	int	index;
	int	index_rgb;

	index = 0;
	while (line[index] != 'C')
		index++;
	if (line[index + 1] == ' ' || line[index + 1] == '\t')
	{
		while (line[index] == ' ' || line[index] == '\t')
			index++;
		index_rgb = 0;
		while (index_rgb < 3)
		{
			gamedata->map_ceilingcolor[index_rgb] = get_colorcode(line + index);
			index_rgb++;
			index = go_to_next_colorcode(line, index);
		}
	}
	else
		return ('c');
	return ('C');
}
