/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorfanu <lorfanu@student.42wolfsburg.de>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 16:51:48 by lorfanu           #+#    #+#             */
/*   Updated: 2022/10/20 16:54:07 by lorfanu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_texture(t_gamedata *gdata, t_texture *txt, char *elem, int val)
{
	printf("%s\n", elem);
	txt->img = mlx_xpm_file_to_image(gdata->mlx, elem,
			&txt->width, &txt->height);
	if (!txt->img)
	{
		ft_putstr_fd("Invalid texture\n", 1);
		exit(1);
		//maybe some freeing will be needed
	}
	txt->addr = mlx_get_data_addr(txt->img, &txt->bits_per_pixel,
			&txt->line_length, &txt->endian);
	txt->pix_y = 0;
	txt->pix_x = 0;
	txt->txt = val;
}

t_img	*ft_t_img(void)
{
	static t_img			img;
	static t_texture		no;
	static t_texture		so;
	static t_texture		we;
	static t_texture		ea;

	if (!img.init)
	{
		img.no = &no;
		img.so = &so;
		img.we = &we;
		img.ea = &ea;
		img.f = 0;
		img.c = 0;
		img.init = 1;
	}
	return (&img);
}

t_gamedata	*ft_t_gamedata(void)
{
	static t_gamedata	gamedata;

	if (!gamedata.init)
	{
		gamedata.map_x = 0;
		gamedata.map_y = 0;
		gamedata.pos = 0;
		gamedata.init = 1;
		// gamedata.player_angle = 0;
		// gamedata.speed = 3.0;
		// gamedata.rotation = 3;
		// gamedata.radius = 0.3;
		// gamedata.map_on = 1;
	}
	return (&gamedata);
}

void	init_color(int *color, char *element)
{
	char	**temp;
	int		r;
	int		g;
	int		b;

	temp = ft_split(element, ',');
	if (*temp)
	{
		r = ft_atoi(temp[0]);
		g = ft_atoi(temp[1]);
		b = ft_atoi(temp[2]);
		// ft_free **temp
		if (r <= 255 && r >= 0 && g <= 255 && g >= 0 && b <= 255 && b >= 0)
		{
			*color = 65536 * r + 256 * g + b;
			return ;
		}		
	}
	ft_putstr_fd("Invalid colour\n", 1);
	exit(1);
	//maybe some freeing will be needed
}