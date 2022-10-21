/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:09:18 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/21 17:57:33 by aionescu         ###   ########.fr       */
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

void	check_all_file(char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Ntz ntz -wrong path\n", 1);
		exit(1);
		//maybe some freeing will be needed
	}
	read_and_init_element(fd);
//function to validate the map to be added here
}

int	main(int argc, char **argv)
{
	t_gamedata		*gamedata;
	// t_resolution	resolution;

	// gamedata = ft_t_gamedata();
	initialize_gamedata(gamedata);
	if (parse_and_report(argc, argv, gamedata) != 0)
		return (1);
	gamedata->mlx = mlx_init();
	check_all_file(argv[1]);
	gamedata->win = mlx_new_window(gamedata->mlx, 640, 640, "cube3D");
	gamedata->img = mlx_new_image(gamedata->mlx, 640, 640);
	// // print_gamedata(&gamedata);
	// printf("No errors so far?\n");
	//
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
