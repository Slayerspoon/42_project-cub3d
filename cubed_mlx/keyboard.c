/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:56:25 by lorfanu           #+#    #+#             */
/*   Updated: 2022/10/27 18:24:17 by lorfanu          ###   ########.fr       */
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
	// 	player_moves_forward(game);
	// else if (key == 's' || key == 'S')
	// 	player_moves_backward(game);
	// else if (key == 'd' || key == 'D')
	// 	player_moves_right(game);
	// else if (key == 'a' || key == 'A')
	// 	player_moves_left(game);
	// else if (key == KEY_RIGHT_ARROW)
	// 	player_rotates_right(game);
	// else if (key == KEY_LEFT_ARROW)
	// 	player_rotates_left(game);
	if (key == KEY_ESCAPE)
		game_exit(game, "\nThanks for playing\n\n", EXIT_SUCCESS);
	return (0);
}

void	free_textures(t_texture *txt, t_gamedata *game)
{
	if (txt->img_north)
		mlx_destroy_image(game->mlx, txt->img_north->imag);
	if (txt->img_south)
		mlx_destroy_image(game->mlx, txt->img_south->imag);
	if (txt->img_east)
		mlx_destroy_image(game->mlx, txt->img_east->imag);
	if (txt->img_west)
		mlx_destroy_image(game->mlx, txt->img_west->imag);
	free(txt);
}

void	mlx_cleanup(t_gamedata *game)
{
	if (game->tex)
		free_textures(game->tex, game);
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
	// some extra free ?
	exit(exit_status);
}
