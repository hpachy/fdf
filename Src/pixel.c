/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:01:22 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/15 11:57:41 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	color_back_ground(t_data data)
{
	int		up;
	int		count;

	count = (data.x * data.y) * 4;
	up = 0;
	while (up != count)
	{
		data.picture[up] = data.keyhook->b;
		data.picture[up + 1] = data.keyhook->g;
		data.picture[up + 2] = data.keyhook->r;
		data.picture[up + 3] = 0x00;
		up = up + 4;
	}
}

void	sup_zero(int x, int y, t_data data, int z)
{
	if (z > 130)
	{
		(data.picture)[(x * 4) + (y * data.size_line)] = 255;
		(data.picture)[(x * 4) + (y * data.size_line) + 1] = 255;
		(data.picture)[(x * 4) + (y * data.size_line) + 2] = 255;
		(data.picture)[(x * 4) + (y * data.size_line) + 3] = 0;
	}
	else if (z <= 50 && z > 0)
	{
		(data.picture)[(x * 4) + (y * data.size_line)] = 0;
		(data.picture)[(x * 4) + (y * data.size_line) + 1] = 200;
		(data.picture)[(x * 4) + (y * data.size_line) + 2] = 0;
		(data.picture)[(x * 4) + (y * data.size_line) + 3] = 0;
	}
	else if (z <= 130 && z >= 50)
	{
		(data.picture)[(x * 4) + (y * data.size_line)] = 19;
		(data.picture)[(x * 4) + (y * data.size_line) + 1] = 69;
		(data.picture)[(x * 4) + (y * data.size_line) + 2] = 139;
		(data.picture)[(x * 4) + (y * data.size_line) + 3] = 0;
	}
}

void	light_on(int x, int y, t_data p, int z)
{
	if (p.keyhook->color == 0)
	{
		if ((x >= 0 && x < p.x) && (y >= 0 && y < p.y))
		{
			(p.picture)[(x * 4) + (y * p.size_line)] = 255 - p.keyhook->b;
			(p.picture)[(x * 4) + (y * p.size_line) + 1] = 255 - p.keyhook->g;
			(p.picture)[(x * 4) + (y * p.size_line) + 2] = 255 - p.keyhook->r;
			(p.picture)[(x * 4) + (y * p.size_line) + 3] = 0;
		}
	}
	if (p.keyhook->color == 1)
	{
		if ((x >= 0 && x < p.x) && (y >= 0 && y < p.y))
		{
			if (z > 0)
				sup_zero(x, y, p, z);
			else if (z <= 0)
			{
				(p.picture)[(x * 4) + (y * p.size_line)] = 150;
				(p.picture)[(x * 4) + (y * p.size_line) + 1] = 0;
				(p.picture)[(x * 4) + (y * p.size_line) + 2] = 0;
				(p.picture)[(x * 4) + (y * p.size_line) + 3] = 0;
			}
		}
	}
}
