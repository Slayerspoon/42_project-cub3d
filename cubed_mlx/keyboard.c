/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:56:25 by lorfanu           #+#    #+#             */
/*   Updated: 2022/10/27 18:20:22 by lorfanu          ###   ########.fr       */
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
