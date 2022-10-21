/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:11:04 by aionescu          #+#    #+#             */
/*   Updated: 2022/10/15 16:11:44 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// This function returns the first non-space character it finds in a string,
// starting from the position that gets passed as a parameter.
char	first_nonspace_char(char *line)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] == '\n')
			return ('\n');
		else if (line[index] != ' ' && line[index] != '\t')
			return (line[index]);
		index++;
	}
	return ('\0');
}
