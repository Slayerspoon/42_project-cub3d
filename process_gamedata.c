/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_gamedata.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:16:21 by aionescu          #+#    #+#             */
/*   Updated: 2022/08/26 19:26:18 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*read_to_string(int fd)
{
	char	*final_str;
	int		index;

	final_str = ft_calloc(1000000, sizeof(char));
	index = 0;
	while (read(fd, &(final_str[index]), 1) > 0)
		index++;
	return (final_str);
}

char	first_nonspace_char(char *line)
{
	int	index;

	index = 0;
	while (line[index] != '\0')
	{
		if (line[index] != ' ')
			return (line[index]);
		index++;
	}
	return ('\0');
}

char	process_valid_line(char *line, t_gamedata *gamedata)
{
	char	processed_type;

	if (first_nonspace_char(line) == 'N')
		processed_type = process_north(line, gamedata);
	else if (first_nonspace_char(line) == 'S')
		processed_type = process_south(line, gamedata);
	else if (first_nonspace_char(line) == 'E')
		processed_type = process_east(line, gamedata);
	else if (first_nonspace_char(line) == 'W')
		processed_type = process_west(line, gamedata);
	else if (first_nonspace_char(line) == 'F')
		processed_type = process_floor(line, gamedata);
	else if (first_nonspace_char(line) == 'C')
		processed_type = process_ceiling(line, gamedata);
	else if (first_nonspace_char(line) == '1')
		processed_type = process_layout(line, gamedata);
	else
		processed_type = '\0';
	return (processed_type);
}

int	populate_gamedata(char *source, t_gamedata *gamedata)
{
	char	processed_line_result;
	char	*position;

	position = source;
	while (*position != '\0')
	{
		processed_line_result = process_valid_line(position, gamedata);
		if ('A' <= processed_line_result && processed_line_result <= 'Z')
		{
			while (*position != '\n' && *position != '\0')
				position++;
			position++;
		}
		else
			return (1);
	}
	return (0);
}

int	process_gamedata(char *map_file_path, t_gamedata *gamedata)
{
	int		fd;
	char	*input_file;
	char	*temp_filedata;
	int		processing_status;

	input_file = ft_strnstr(map_file_path, ".cub", ft_strlen(map_file_path));
	if (input_file != NULL && ft_strlen(input_file) == 4)
		fd = open(map_file_path, O_RDONLY);
	else
		return (1);
	if (fd == -1)
		return (2);
	temp_filedata = read_to_string(fd);
	processing_status = populate_gamedata(temp_filedata, gamedata);
	free(temp_filedata);
	close(fd);
	return (processing_status);
}
