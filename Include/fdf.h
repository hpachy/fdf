/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:56:33 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/04 11:38:27 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <fcntl.h>
# include "libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_keyhook
{
	long	int	trans_y;
	long	int	trans_x;
	float		trans_z;
	int			r;
	int			g;
	int			b;
	float		color;
	int			index_color;
	long	int	zoom_y;
	long	int	zoom_x;
}				t_keyhook;

typedef	struct	s_test
{
	float		x;
	float		y;
	float		dx;
	float		dy;
	int			i;
	float		xinc;
	float		yinc;
	float		cumul;
}				t_test;

typedef	struct	s_pointmax
{
	float		y_max;
}				t_pointmax;

typedef	struct	s_board
{
	float		z;
	float		x;
	float		y;
	int			y_max;
}				t_board;

typedef	struct	s_data
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*picture;
	char		*argc;
	int			dian;
	int			x;
	int			y;
	int			nombre_x;
	int			*tab_int;
	int			index;
	int			bits;
	int			size_line;
	t_keyhook	*keyhook;
	t_board		**board;
}				t_data;

double			my_abs(double a);
void			write_on_image(t_data *data);
int				put_here_now(int n, float y, float q, t_data *data);
int				with_out_parser(t_data *data, t_list *list);
int				put_in(int i, char **tab, float y, t_data *data);
void			ccinit(t_data *data);
int				key_hook(int keycode, t_data *data, t_list *list);
int				my_parser(char *argc, t_data *data, t_list *list, int fd);
void			makes_my_grid(t_data *data);
void			light_on(int x, int y, t_data data, int z);
void			modif_hauteur(t_data data, int y_max);
void			color_back_ground(t_data data);
void			my_dx_sup(t_data data, t_test *testpos, int z);
void			my_dx_inf(t_data data, t_test *testpos, int z);
void			color_back_ground(t_data data);
#endif
