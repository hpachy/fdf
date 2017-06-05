/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:01:34 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/15 11:29:44 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	ccinit(t_data *data)
{
	data->keyhook->trans_y = data->y / 2;
	data->keyhook->trans_x = data->x / 2;
	data->keyhook->trans_z = 0.25;
	data->keyhook->r = 0;
	data->keyhook->g = 0;
	data->keyhook->b = 0;
	data->keyhook->index_color = 1;
	data->keyhook->color = 0;
	data->keyhook->zoom_x = 2;
	data->keyhook->zoom_y = 2;
}

void	translation(int keycode, t_data *data)
{
	if (keycode == 124)
		data->keyhook->trans_x += 50;
	if (keycode == 123)
		data->keyhook->trans_x -= 50;
	if (keycode == 125)
		data->keyhook->trans_y += 50;
	if (keycode == 126)
		data->keyhook->trans_y -= 50;
}

void	color(int keycode, t_data *data)
{
	if (keycode == 5 && data->keyhook->index_color < 101)
		data->keyhook->g += data->keyhook->index_color;
	if (keycode == 11 && data->keyhook->index_color < 101)
		data->keyhook->b += data->keyhook->index_color;
	if (keycode == 15 && data->keyhook->index_color < 101)
		data->keyhook->r += data->keyhook->index_color;
	if (keycode == 4 && data->keyhook->index_color > -101)
		data->keyhook->g -= data->keyhook->index_color;
	if (keycode == 45 && data->keyhook->index_color > -101)
		data->keyhook->b -= data->keyhook->index_color;
	if (keycode == 17 && data->keyhook->index_color > -101)
		data->keyhook->r -= data->keyhook->index_color;
	if (keycode == 35)
	{
		data->keyhook->r = 0;
		data->keyhook->g = 0;
		data->keyhook->b = 0;
	}
	if (data->keyhook->r >= 256 || data->keyhook->r < 0)
		data->keyhook->r = 0;
	if (data->keyhook->g >= 256 || data->keyhook->g < 0)
		data->keyhook->g = 0;
	if (data->keyhook->b >= 256 || data->keyhook->b < 0)
		data->keyhook->b = 0;
}

void	zoom_and_z(int keycode, t_data *data)
{
	if (keycode == 69)
	{
		data->keyhook->zoom_y += 1;
		data->keyhook->zoom_x += 1;
	}
	if (keycode == 78 && data->keyhook->zoom_x >= 1 &&
		data->keyhook->zoom_y >= 1)
	{
		data->keyhook->zoom_y -= 1;
		data->keyhook->zoom_x -= 1;
	}
	if (keycode == 6)
		data->keyhook->trans_z += 0.1;
	if (keycode == 0)
		data->keyhook->trans_z -= 0.1;
}

int		key_hook(int keycode, t_data *data, t_list *list)
{
	if (keycode == 269 || keycode == 258 || keycode == 279 || keycode == 262
		|| keycode == 259 || keycode == 260 || keycode == 261 || keycode == 256
		|| keycode == 257 || keycode == 272 || keycode == 277 || keycode == 264)
		return (0);
	if (keycode == 53)
		exit(0);
	color_back_ground(*data);
	translation(keycode, data);
	zoom_and_z(keycode, data);
	color(keycode, data);
	if (keycode == 37 && data->keyhook->index_color < 100)
		data->keyhook->index_color += 1;
	if (keycode == 38 && data->keyhook->index_color > -100)
		data->keyhook->index_color -= 1;
	if (keycode == 34)
		data->keyhook->color = 0;
	if (keycode == 40)
		data->keyhook->color = 1;
	with_out_parser(data, list);
	mlx_put_image_to_window(data->mlx, data->win, data->img, -1, -1);
	write_on_image(data);
	mlx_do_key_autorepeaton(data->mlx);
	return (0);
}
