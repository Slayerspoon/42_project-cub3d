/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:09:18 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/18 19:02:09 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// int	exit_game(t_gamedata *gamedata)
// {
// 	free(gamedata->map_layout);
// 	mlx_destroy_window(gamedata->mlx, gamedata->win);
// 	exit(0);
// }

// char	determine_facing(int keycode)
// {
// 	if (keycode == 97)
// 		return ('L');
// 	else if (keycode == 119)
// 		return ('U');
// 	else if (keycode == 100)
// 		return ('R');
// 	else
// 		return ('D');
// }

// int	key_hook(int keycode, t_vars *vars)
// {
// 	char	facing;
// 	int		moved;

// 	facing = 'U';
// 	moved = 0;
// 	if (keycode == 97 || keycode == 100 || keycode == 115 || keycode == 119)
// 	{
// 		facing = determine_facing(keycode);
// 		moved = update_map(vars->map, facing);
// 		if (moved != 0)
// 		{
// 			vars->moves++;
// 			printf("Moves made so far: %d\n", vars->moves);
// 		}
// 		display_map(*vars, vars->imgs, vars->map, facing);
// 		if (moved == 2)
// 		{
// 			printf("Thanks for all the fish!\n");
// 			exit_game(vars);
// 		}
// 	}
// 	else if (keycode == 65307)
// 		exit_game(vars);
// 	return (0);
// }

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

void	print_gamedata(t_gamedata *gamedata)
{
	printf("--- GAME MAP START ---\n");
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			printf("%c", gamedata->map_layout[i][j]);
		}
		printf("\n");
	}
	printf("---- GAME MAP END ----\n");
	for (int k = 0; k < 4; k++)
	{
		printf("%s\n", gamedata->map_nsew[k]);
	}
	for (int l = 0; l < 3; l++)
	{
		printf("%d ", gamedata->map_floorcolor[l]);
	}
	printf("\n");
	for (int m = 0; m < 3; m++)
	{
		printf("%d ", gamedata->map_ceilingcolor[m]);
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	t_gamedata		gamedata;
	// t_resolution	resolution;

	if (argc != 2 || file_structure_check(argv[1]) != 0)
	{
		printf("Error:\nInvalid map provided.\n");
		return (1);
	}
	initialize_gamedata(&gamedata);
	if (argc != 2 || process_gamedata(argv[1], &gamedata) != 0)
	{
		printf("Error:\nInvalid map information provided.\n");
		return (1);
	}
	// LEFT OFF HERE! Everything in the flow up to this point has been implemented and needs to be tested!
	print_gamedata(&gamedata);
	// if (set_resolution(&resolution, gamedata) != 0)
	// {
	// 	printf("Error:\nThe provided map is too big.\n");
	// 	return (1);
	// }
	// gamedata.mlx = mlx_init();
	// gamedata.win = mlx_new_window(gamedata.mlx, resolution.x, resolution.y, "So long!");
	// gamedata.imgs = create_image_array(gamedata.mlx);
	// gamedata.moves = 0;
	// display_map(gamedata, gamedata.imgs, gamedata.map_layout, 'U');
	// mlx_key_hook(gamedata.win, key_hook, &gamedata);
	// mlx_hook(gamedata.win, 17, 1L << 17, exit_game, &gamedata);
	// mlx_loop(gamedata.mlx);
	return (0);
}
