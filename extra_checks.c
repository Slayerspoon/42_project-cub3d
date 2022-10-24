/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:13:55 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/24 20:10:24 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function checks if the provided texture paths are accessible.
int	path_nsew_check(t_gamedata *gamedata)
{
	int	index;
	int	fd;

	fd = 0;
	index = 0;
	while (index < 4)
	{
		fd = open(gamedata->map_nsew[index], O_RDONLY);
		if (fd == -1)
			return (31 + index);
		close(fd);
		index++;
	}
	return (0);
}
