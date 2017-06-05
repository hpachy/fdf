/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 11:15:05 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/04 12:10:22 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"
#include "libft.h"

void	opti_line(t_data data, t_board board, t_board boardbis)
{
	t_test		testpos;

	testpos.x = (float)board.x;
	testpos.y = (float)board.y;
	testpos.dx = (float)boardbis.x - (float)board.x;
	testpos.dy = (float)boardbis.y - (float)board.y;
	testpos.xinc = (testpos.dx > 0.0) ? 1.0 : -1.0;
	testpos.yinc = (testpos.dy > 0.0) ? 1.0 : -1.0;
	testpos.dx = my_abs(testpos.dx);
	testpos.dy = my_abs(testpos.dy);
	light_on(testpos.x, testpos.y, data, board.z);
	if (testpos.dx > testpos.dy)
		my_dx_sup(data, &testpos, board.z);
	else
		my_dx_inf(data, &testpos, board.z);
}

void	makes_my_grid(t_data *data)
{
	t_pointmax		pointmax;
	int				x;
	int				y;
	int				y_max;

	x = 0;
	y_max = (data->board[0][0]).y_max;
	pointmax.y_max = (data->board[0][0]).y_max;
	modif_hauteur(*data, y_max);
	y = 0;
	while (y < pointmax.y_max)
	{
		pointmax.y_max = (data->board[y][x]).y_max;
		while (x < data->tab_int[y])
		{
			if (x != (data->tab_int[y] - 1))
				opti_line(*data, (data->board[y][x]), (data->board[y][x + 1]));
			if (y != (pointmax.y_max - 1))
				opti_line(*data, (data->board[y][x]), (data->board[y + 1][x]));
			x++;
		}
		x = 0;
		y++;
	}
}

void	write_on_image(t_data *data)
{
	write(1, "----------------------------------------------------\n", 53);
	write(1, "| changer les couleurs en fonction du relief : I/K |\n", 53);
	write(1, "| fleches directionnelles pour se deplacer         |\n", 53);
	write(1, "| changement de couleur : R/T; G/H; B/N            |\n", 53);
	write(1, "| changer le relief : Z/A                          |\n", 53);
	write(1, "| ZOOMER : +/-                                     |\n", 53);
	write(1, "| index: J/L                                       |\n", 53);
	write(1, "| Push P to clean color                            |\n", 53);
	write(1, "----------------------------------------------------\n", 53);
	write(1, "R = ", 4);
	ft_putnbr(((*data).keyhook)->r);
	write(1, "\n", 1);
	write(1, "G = ", 4);
	ft_putnbr(((*data).keyhook)->g);
	write(1, "\n", 1);
	write(1, "B = ", 4);
	ft_putnbr(((*data).keyhook)->b);
	write(1, "\n", 1);
}

int		error(int a)
{
	if (a == 1)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> wrong numbers of arguments <==\n\n", 36);
		write(1, "==> first: WIN int X ; second : WIN int Y ;", 43);
		write(1, " third : your map <==\n\n", 23);
	}
	if (a == 2)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> your map is false or your files false <==\n\n", 47);
	}
	if (a == 3)
	{
		write(1, "\n\n(>_<) AIE!!! ", 15);
		write(1, "==> your Win int x or Win int y superior to 2500 <==\n", 53);
		write(1, "\n==> try to put Win int x = 2500 and Win int y = 1450", 53);
		write(1, " to have good vission on your map if she's big! <==\n", 52);
	}
	return (1);
}

int		main(int argv, char **argc)
{
	t_data		p;
	int			fd;
	t_list		list;

	p.argc = ft_strnew(1);
	if (!(p.keyhook = malloc(sizeof(t_keyhook) * 1)))
		return (error(2));
	if (argv != 4)
		return (error(1));
	if ((p.x = my_abs(ft_atoi(argc[1]))) > 2500 ||
		(p.y = my_abs(ft_atoi(argc[2]))) > 2500)
		return (error(3));
	ccinit(&p);
	p.mlx = mlx_init();
	p.win = mlx_new_window(p.mlx, p.x, p.y, "projet graph 42");
	p.img = mlx_new_image(p.mlx, p.x, p.y);
	p.picture = mlx_get_data_addr(p.img, &(p.bits), &(p.size_line), &(p.dian));
	color_back_ground(p);
	if (my_parser(argc[3], &p, &list, fd) == -1)
		return (error(2));
	mlx_hook(p.win, 2, 1L << 2, &key_hook, &p);
	mlx_put_image_to_window(p.mlx, p.win, p.img, -1, -1);
	write_on_image(&p);
	mlx_loop(p.mlx);
	return (0);
}
