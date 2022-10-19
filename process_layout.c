/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_layout.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:54:53 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/19 19:05:03 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function is used to check if there is any non-space character before
// the end of the current line, starting from the passed pointer.
// Returns 0 if false, or 1 if true.
int	empty_space_ahead(char *start_ptr)
{
	int	flag_empty;
	int	index;

	flag_empty = 1;
	index = 0;
	while (start_ptr[index] != '\n' && start_ptr[index] != '\0')
	{
		if (start_ptr[index] != ' ' && start_ptr[index] != '\t')
		{
			flag_empty = 0;
			break ;
		}
		index++;
	}
	return (flag_empty);
}

// This function copies every character that represents the layout of the
// playable area into the the gamedata->map_layout[][] variable.
// The return value 'L' means success and the return value 'l' means error.
char	process_layout(char *p, t_gamedata *gamedata)
{
	int	pos;
	int	row;
	int	col;

	pos = 0;
	row = 0;
	col = 0;
	while (p[pos] != '\0')
	{
		if (p[pos] == '\n' || empty_space_ahead(p + pos))
		{
			gamedata->map_layout[row][col] = '\0';
			row++;
			col = 0;
		}
		else if (ft_strchr("NSEW01 ", p[pos]) != NULL)
		{
			gamedata->map_layout[row][col] = p[pos];
			col++;
		}
		else
			return ('l');
		pos++;
	}
	return ('L');
}
