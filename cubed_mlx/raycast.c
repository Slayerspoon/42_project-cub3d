/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 23:37:57 by lorfanu           #+#    #+#             */
/*   Updated: 2022/11/02 13:30:03 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_raycast(int x, t_raycast *ray, t_player *player)
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
		x++;
	}
}