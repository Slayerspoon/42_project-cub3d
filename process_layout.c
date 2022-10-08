/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:53 by aionescu          #+#    #+#             */
/*   Updated: 2022/08/26 17:47:13 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	process_layout(char *start, t_gamedata *gamedata)
{
	int	pos;
	int	row;
	int	col;

	pos = 0;
	row = 0;
	col = 0;
	while (start[pos++] != '\0')
	{
		if (start[pos] == '\n')
		{
			gamedata->map_layout[row][col] = '\0';
			row++;
			col = 0;
		}
		else if (start[pos] == ' ' || start[pos] == '1' || start[pos] == '0'
			|| start[pos] == 'N' || start[pos] == 'S' || start[pos] == 'E')
		{
			gamedata->map_layout[row][col] = start[pos];
			col++;
		}
		else
			return ('l');
	}
	return ('L');
}
