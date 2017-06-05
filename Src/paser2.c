/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:14:14 by hpachy            #+#    #+#             */
/*   Updated: 2016/12/15 11:53:39 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"

int		put_here_now(int n, float y, float q, t_data *data)
{
	float	x;
	int		i;
	int		tmp;

	q = 0.0;
	x = 0.0;
	i = 0;
	while (i < n)
	{
		(((*data).board)[(int)y][(int)x]).x = x + (data->keyhook->trans_x);
		(((*data).board)[(int)y][(int)x]).y = y + (data->keyhook->trans_y);
		x += 1.0;
		i++;
	}
	return ((int)x);
}

int		with_out_parser(t_data *data, t_list *list)
{
	float	y;

	y = 0.0;
	while (list)
	{
		if (((put_here_now((data->tab_int)[(int)y], y, data->index,
		data)) == -1))
			return (-1);
		y += 1.0;
		list = list->next;
	}
	makes_my_grid(data);
	return (0);
}
