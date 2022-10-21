/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:51:31 by lorfanu           #+#    #+#             */
/*   Updated: 2022/10/20 16:53:55 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	read_and_init_element(int fd)
{
	int		i;
	char	*temp;

	i = 6;
	temp = get_next_line(fd);
	while (i && temp)
	{
		i -= find_element(temp, fd);
		free(temp);
		temp = get_next_line(fd);
	}
	if (temp)
		free(temp);
	if (i != 0)
	{
		close (fd);
		ft_putstr_fd("Missing element\n", 1);
		exit(1);
		//maybe some freeing will be needed
	}
}

int	check_identifier(t_img *img, char *temp)
{
	if (!*temp)
		return (0);
	if (ft_strncmp(temp, "NO", 2) == 0 && !img->no->img)
		return (NO);
	if (ft_strncmp(temp, "SO", 2) == 0 && !img->so->img)
		return (SO);
	if (ft_strncmp(temp, "WE", 2) == 0 && !img->we->img)
		return (WE);
	if (ft_strncmp(temp, "EA", 2) == 0 && !img->ea->img)
		return (EA);
	if (ft_strncmp(temp, "F", 1) == 0 && !img->f)
		return (F);
	if (ft_strncmp(temp, "C", 1) == 0 && !img->c)
		return (C);
	return (0);
}

int	find_element(char *element, int fd)
{
	int	val;
	int	i;

	i = 0;
	val = 0;
	while (*element && check_white_spaces(*element))
		element++;
	val = check_identifier(ft_t_img(), element);
	if (val > 0)
	{
		element++;
		if (val < 5)
			element++;
		while (check_white_spaces(*element))
			element++;
		while (element[i] && !check_white_spaces(element[i]))
			i++;
		element[i] = '\0';
		if (init_element(element, val))
			return (1);
		close (fd);
		ft_putstr_fd("Element not found\n", 1);
		exit(1);
		//maybe some freeing will be needed
	}
	return (0);
}

int	init_element(char *element, int val)
{
	if (element && val == NO)
		init_texture(ft_t_gamedata(), ft_t_img()->no, element, val);
	else if (element && val == SO)
		init_texture(ft_t_gamedata(), ft_t_img()->so, element, val);
	else if (element && val == WE)
		init_texture(ft_t_gamedata(), ft_t_img()->we, element, val);
	else if (element && val == EA)
		init_texture(ft_t_gamedata(), ft_t_img()->ea, element, val);
	else if (element && val == F)
		init_color(&ft_t_img()->f, element);
	else if (element && val == C)
		init_color(&ft_t_img()->c, element);
	else
		return (0);
	return (1);
}