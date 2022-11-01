/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_floor_ceiling.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 17:19:08 by lorfanu           #+#    #+#             */
/*   Updated: 2022/10/26 20:14:49 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	game_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*pixel_dst;

	pixel_dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)pixel_dst = color;
}

/* "verLine" ft put into draw_ceiling, draw_floor
** norminette restriction on no. vars necessitated
** two sep fts to draw floor and ceiling.
** nested while loop draws vertical lines
*/

void	render_ceiling(t_gamedata *game, int y1, int y2, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = y1;
		while (j < y2)
		{
			game_mlx_pixel_put(game->img, i, j, game->tex->ceiling);
			j++;
		}
		i++;
	}
}

void	render_floor(t_gamedata *game, int y1, int y2, int x)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = y1;
		while (j < y2)
		{
			game_mlx_pixel_put(game->img, i, j, game->tex->floor);
			j++;
		}
		i++;
	}
}

t_img	*put_floor_ceiling(t_gamedata *game)
{
	int	height;
	int	width;

	height = S_HEIGHT;
	width = S_WIDTH;
	render_ceiling(game, 0, height / 2, width);
	render_floor(game, height / 2, height, width);
	return (game->img);
}