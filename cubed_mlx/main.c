/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:09:18 by aionescu          #+#    #+#             */
/*   Updated: 2022/11/14 16:53:14 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initialize_gamedata(t_gamedata *gamedata)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i++ < 100)
	{
		while (j++ < 100)
			gamedata->map_layout[i - 1][j - 1] = '\0';
		j = 0;
	}
	while (j++ < 4)
		gamedata->map_nsew[j - 1] = NULL;
	j = 0;
	while (j++ < 3)
		gamedata->map_floorcolor[j - 1] = 666;
	j = 0;
	while (j++ < 3)
		gamedata->map_ceilingcolor[j - 1] = 666;
}

// void	print_gamedata(t_gamedata *gamedata)
// {
// 	printf("--- INITIAL MAP START ---\n");
// 	int	i = 0;
// 	int	j = 0;
// 	while (gamedata->map_layout[j][i] != '\0')
// 	{
// 		while (gamedata->map_layout[j][i] != '\0')
// 		{
// 			printf("%c", gamedata->map_layout[j][i]);
// 			i++;
// 		}
// 		printf("\n");
// 		i = 0;
// 		j++;
// 	}
// 	printf("---- INITIAL MAP END ----\n");
// 	printf("--- FINAL MAP START ---\n");
// 	int	x = 0;
// 	int	y = 0;
// 	while (gamedata->final_map[y][x] != '\0')
// 	{
// 		while (gamedata->final_map[y][x] != '\0')
// 		{
// 			printf("%c", gamedata->final_map[y][x]);
// 			x++;
// 		}
// 		printf("\n");
// 		x = 0;
// 		y++;
// 	}
// 	printf("---- FINAL MAP END ----\n");
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
	gamedata.final_map = generate_final_map(&gamedata);
	// print_gamedata(&gamedata);
	player_init(&gamedata, &player);
	game_init(&gamedata);
	mlx_loop_hook(gamedata.mlx, render_image, &gamedata);
	mlx_hook(gamedata.win, 17, 1L << 0, game_xbutton, &gamedata);
	mlx_hook(gamedata.win, 2, 1L << 0, handle_game_keys, &gamedata);
	mlx_loop(gamedata.mlx);
	return (0);
}
