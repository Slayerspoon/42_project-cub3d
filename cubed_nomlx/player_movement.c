/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:28 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/27 18:52:36 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	update_player_pos(t_gamedata *gamedata)
{
	int	row;
	int	col;

	row = 0;
	col = 0;
	while (gamedata->map_layout[row][col] != '\0')
	{
		while (gamedata->map_layout[row][col] != '\0')
		{
			if (gamedata->map_layout[row][col] == 'N'
				|| gamedata->map_layout[row][col] == 'S'
				|| gamedata->map_layout[row][col] == 'E'
				|| gamedata->map_layout[row][col] == 'W')
			{
				gamedata->player.facing = gamedata->map_layout[row][col];
				gamedata->player.x = col;
				gamedata->player.y = row;
				break ;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}
