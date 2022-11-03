/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:37:57 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/03 18:48:12 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
** ray calculations & DDA (jumping to next square: in x or y direction:
** side 0 - EAST, WEST, side 1 - NORTH, SOUTH) until it hits a wall
** (finding in which square to move to when collision happens)
** t_gamedata *game
*/
void	raycast_handle_wall_dda( t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->side_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->side_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		// if (a wall - 1 is found)
		// 	ray->hit = 1;
	}
}

/*
** function to calculate the steps taken by the player
*/
void	set_player_steps(t_raycast *ray, t_player *p)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = LEFT;
		ray->side_dist_x = (p->x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = RIGHT;
		ray->side_dist_x = (ray->map_x + 1.0 - p->x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = DOWN;
		ray->side_dist_y = (p->y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = UP;
		ray->side_dist_y = (ray->map_y + 1.0 - p->y) * ray->delta_dist_y;
	}
}

void	init_raycast(int x, t_raycast *ray, t_player *player)
{
	ray->hit = 0;
	ray->step_x = 0;
	ray->step_y = 0;
	ray->ray_dir_x
		= player->dir_x + player->plane_x * (2 * x / (double)S_WIDTH - 1);
	ray->ray_dir_y
		= player->dir_y + player->plane_y * (2 * x / (double)S_WIDTH - 1);
	ray->map_x = (int)player->x;
	ray->map_y = (int)player->y;
	if (ray->ray_dir_x == 0)
		ray->delta_dist_x = 1e30;
	else
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	if (ray->ray_dir_y == 0)
		ray->delta_dist_y = 1e30;
	else
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	raycast(t_gamedata *game)
{
	int			x;
	t_raycast	*raycast;

	raycast = ft_calloc(sizeof(t_raycast), 1);
	game->ray = raycast;
	x = 0;
	while (x < S_WIDTH)
	{
		init_raycast(x, raycast, game->player);
		set_player_steps(raycast, game->player);
		x++;
	}
}