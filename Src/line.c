/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 11:01:34 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/15 11:43:04 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

double	my_abs(double a)
{
	if (a < 0)
		a = -a;
	return (a);
}

void	my_dx_sup(t_data data, t_test *testpos, int z)
{
	testpos->cumul = testpos->dx / 2.0;
	testpos->i = 1;
	while (testpos->i <= testpos->dx)
	{
		testpos->x += testpos->xinc;
		testpos->cumul += testpos->dy;
		if (testpos->cumul >= testpos->dx)
		{
			testpos->cumul -= testpos->dx;
			testpos->y += testpos->yinc;
		}
		light_on(testpos->x, testpos->y, data, z);
		testpos->i++;
	}
}

void	my_dx_inf(t_data data, t_test *testpos, int z)
{
	testpos->cumul = testpos->dy / 2.0;
	testpos->i = 1;
	while (testpos->i <= testpos->dy)
	{
		testpos->y += testpos->yinc;
		testpos->cumul += testpos->dx;
		if (testpos->cumul >= testpos->dy)
		{
			testpos->cumul -= testpos->dy;
			testpos->x += testpos->xinc;
		}
		light_on(testpos->x, testpos->y, data, z);
		testpos->i++;
	}
}

void	modif_hauteur(t_data data, int y_max)
{
	int			x;
	int			y;
	float		n;
	float		i;

	x = 0;
	y = 0;
	i = 0.5;
	n = 0.1;
	while (y < y_max)
	{
		while (x < data.tab_int[y])
		{
			((data.board)[y][x]).x = (((data.board)[0][0]).x +
			(x - y) * data.keyhook->zoom_x);
			((data.board)[y][x]).y = (((data.board)[0][0]).y + (x + y) *
			data.keyhook->zoom_y * i - (((int)((((data.board)[y][x]).z) * 4)))
			* (2 * n * data.keyhook->trans_z));
			x++;
		}
		x = 0;
		y++;
	}
}
