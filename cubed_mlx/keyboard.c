/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:56:25 by lorfanu           #+#    #+#             */
/*   Updated: 2022/10/31 12:32:02 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	game_xbutton(t_gamedata *game)
{
	game_exit(game, "\nThanks for playing\n\n", EXIT_SUCCESS);
	return (0);
}

int	handle_game_keys(int key, t_gamedata *game)
{
	// if (key == 'w' || key == 'W')
	// 	move_forward_w(game);
	// else if (key == 's' || key == 'S')
	// 	move_backward_s(game);
	// else if (key == 'd' || key == 'D')
	// move_right_d(game);
	// else if (key == 'a' || key == 'A')
	// 	move_left_a(game);
	// else if (key == KEY_RIGHT_ARROW)
	// 	rotate_right(game);
	// else if (key == KEY_LEFT_ARROW)
	// 	rotate_left(game);
	if (key == KEY_ESCAPE)
		game_exit(game, "\nThanks for playing\n\n", EXIT_SUCCESS);
	return (0);
}

void	free_textures(t_texture *txt, t_img *image, t_gamedata *game)
{
	if (txt->img_north)
		mlx_destroy_image(game->mlx, txt->img_north->imag);
	if (txt->img_south)
		mlx_destroy_image(game->mlx, txt->img_south->imag);
	if (txt->img_east)
		mlx_destroy_image(game->mlx, txt->img_east->imag);
	if (txt->img_west)
		mlx_destroy_image(game->mlx, txt->img_west->imag);
	if (txt->img_north)
		free(txt->img_north);
	if (txt->img_south)
		free(txt->img_south);
	if (txt->img_east)
		free(txt->img_east);
	if (txt->img_west)
		free(txt->img_west);
	if (game->tex)
		free(game->tex);
	free(txt);
	if (game->img->imag)
		free(game->img->imag);
	if (game->img)
		free(game->img);
	free(image);
}

void	mlx_cleanup(t_gamedata *game)
{
	if (game->tex)
		free_textures(game->tex, game->img, game);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

void	game_exit(t_gamedata *game, char *err_msg, int exit_status)
{
	if (game)
		mlx_cleanup(game);
	if (err_msg)
		ft_putstr_fd(err_msg, 1);
	if (game->map_nsew[0])
		free(game->map_nsew[0]);
	if (game->map_nsew[1])
		free(game->map_nsew[1]);
	if (game->map_nsew[2])
		free(game->map_nsew[2]);
	if (game->map_nsew[3])
		free(game->map_nsew[3]);
	if (game->mlx)
		free(game->mlx);
	exit(exit_status);
}
