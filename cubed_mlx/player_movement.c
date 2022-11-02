/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:46:28 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/02 13:38:32 by lorfanu          ###   ########.fr       */
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
				gamedata->player->facing = gamedata->map_layout[row][col];
				gamedata->player->x = col;
				gamedata->player->y = row;
				break ;
			}
			col++;
		}
		col = 0;
		row++;
	}
	return (0);
}

/*
** init direction vector & the 2d raycaster version of camera plane
** for player facing X (west/east), where FOV = field of view (value 66)
** 0.66 = PLAYER_FOV / 100 (* -1 when is facing W)
*/
static void	handle_player_face_x(t_gamedata *game, t_player *player)
{
	if (game->player->facing == 'E')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (game->player->facing == 'W')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

/*
** init direction vector & the 2d raycaster version of camera plane
** for player facing Y (north/south), where FOV = field of view (value 66)
** 0.66 = PLAYER_FOV / 100 (* -1 when is facing south)
*/
static void	handle_player_face_y(t_gamedata *game, t_player *player)
{
	if (game->player->facing == 'N')
	{
		player->dir_x = 0;
		player->dir_y = -1;
		player->plane_x = 0.66;
		player->plane_y = 0;
	}
	else if (game->player->facing == 'S')
	{
		player->dir_x = 0;
		player->dir_y = 1;
		player->plane_x = -0.66;
		player->plane_y = 0;
	}
}

void	player_init(t_gamedata *game, t_player *player)
{
	update_player_pos(game);
	player->x = player->x + 0.5;
	player->y = player->y + 0.5;
	printf("%c facing: \n", game->player->facing);
	handle_player_face_x(game, player);
	handle_player_face_y(game, player);
}