/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:09:18 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/26 20:17:53 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mlx_cleanup(t_gamedata *game)
{
	if (game->tex->img_north)
		mlx_destroy_image(game->mlx, game->tex->img_north);
	if (game->tex->img_south)
		mlx_destroy_image(game->mlx, game->tex->img_south);
	if (game->tex->img_east)
		mlx_destroy_image(game->mlx, game->tex->img_east);
	if (game->tex->img_west)
		mlx_destroy_image(game->mlx, game->tex->img_west);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
}

void	game_exit(t_gamedata *game, char *err_msg)
{
	if (game)
		mlx_cleanup(game);
	if (err_msg)
		ft_putstr_fd(err_msg, 1);
	if (game->tex->img_north)
		free(game->tex->img_north);
	if (game->tex->img_south)
		free(game->tex->img_south);
	if (game->tex->img_east)
		free(game->tex->img_east);
	if (game->tex->img_west)
		free(game->tex->img_west);
	if (game->mlx)
		free(game->mlx);
	// some extra free img paths?
	exit(EXIT_FAILURE);
}

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

int	main(int argc, char **argv)
{
	t_gamedata	gamedata;

	printf("%d\n", argc);
	initialize_gamedata(&gamedata);
	if (parse_and_report(argc, argv, &gamedata) != 0)
		return (1);
	// print_gamedata(&gamedata);
	// printf("No errors so far?\n");
	game_init(&gamedata);
	img_init(&gamedata);
	// texture_init(&gamedata);
	mlx_loop_hook(gamedata.mlx, render_image, &gamedata);
	// mlx_hook(gamedata.win, 17, 1L << 0, game_pressx, &gamedata);
	// mlx_hook(gamedata.win, 2, 1L << 0, game_key, &gamedata);
	mlx_loop(gamedata.mlx);
	return (0);
}
