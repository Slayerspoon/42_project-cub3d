/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:09:18 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/08 20:17:05 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_gamedata(t_gamedata *gamedata)
{
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			gamedata->map_layout[i][j] = '\0';
		}
	}
	for (int k = 0; k < 4; k++)
	{
		gamedata->map_nsew[k] = NULL;
	}
	for (int l = 0; l < 3; l++)
	{
		gamedata->map_floorcolor[l] = 666;
	}
	for (int m = 0; m < 3; m++)
	{
		gamedata->map_ceilingcolor[m] = 666;
	}
}

// void	print_gamedata(t_gamedata *gamedata)
// {
// 	printf("--- GAME MAP START ---\n");
// 	for (int i = 0; i < 100; i++)
// 	{
// 		for (int j = 0; j < 100; j++)
// 		{
// 			printf("%c", gamedata->map_layout[i][j]);
// 		}
// 		printf("\n");
// 	}
// 	printf("---- GAME MAP END ----\n");
// 	for (int k = 0; k < 4; k++)
// 	{
// 		printf("%s\n", gamedata->map_nsew[k]);
// 	}
// 	for (int l = 0; l < 3; l++)
// 	{
// 		printf("%d ", gamedata->map_floorcolor[l]);
// 	}
// 	printf("\n");
// 	for (int m = 0; m < 3; m++)
// 	{
// 		printf("%d ", gamedata->map_ceilingcolor[m]);
// 	}
// 	printf("\n");
// }

int	main(int argc, char **argv)
{
	t_gamedata	gamedata;
	t_player	player;

	gamedata.player = &player;
	initialize_gamedata(&gamedata);
	if (parse_and_report(argc, argv, &gamedata) != 0)
		return (1);
	// print_gamedata(&gamedata);
	printf("No errors so far?\n");
	player_init(&gamedata, &player);
	game_init(&gamedata);
	mlx_loop_hook(gamedata.mlx, render_image, &gamedata);
	mlx_hook(gamedata.win, 17, 1L << 0, game_xbutton, &gamedata);
	mlx_hook(gamedata.win, 2, 1L << 0, handle_game_keys, &gamedata);
	mlx_loop(gamedata.mlx);
	return (0);
}
