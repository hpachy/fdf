/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:14:14 by hpachy            #+#    #+#             */
/*   Updated: 2017/01/04 11:58:06 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fdf.h"
#include <stdio.h>

int		checker_hexa(char *tmp, int index)
{
	int		tmp_int;

	if (tmp[index] == ',')
	{
		index++;
		if (tmp[index] == 48 && tmp[index + 1] == 'x')
			index++;
		else
			return (-1);
		tmp_int = index;
		while (index < (tmp_int + 6))
		{
			index++;
			if (!((tmp[index] >= '0' && tmp[index] <= '9') ||
				(tmp[index] >= 'A' && tmp[index] <= 'F')))
				return (-1);
		}
		if (tmp[index + 1] == ' ')
			return (0);
		return (-1);
	}
	else
		return (-1);
}

int		checker_norm(char *tmp)
{
	int		index;

	index = -1;
	while (tmp[++index] != '\0')
	{
		if (tmp[index] == ',')
		{
			if ((checker_hexa(tmp, index)) == -1)
				return (-1);
			else
				index = index + 8;
		}
		else if (tmp[index] == ' ')
		{
			if (tmp[index + 1] == '\n')
				return (-1);
		}
		else if (!((tmp[index] >= 48 && tmp[index] <= 57) || tmp[index] == 45
			|| tmp[index] == ' '))
			return (-1);
	}
	return (0);
}

int		put_in(int i, char **tab, float y, t_data *data)
{
	float			x;
	int				n;

	x = 0.0;
	n = 0;
	while (n < i)
	{
		(((*data).board)[(int)y][(int)x]).z = (float)(atoi((tab)[n]));
		(((*data).board)[(int)y][(int)x]).x = x + data->x / 2;
		(((*data).board)[(int)y][(int)x]).y = y + data->y / 2;
		(((*data).board)[(int)y][(int)x]).y_max = data->index;
		x += 1.0;
		n++;
	}
	return ((int)x);
}

void	ft_free(char **tab, int i)
{
	int		index;

	index = 0;
	if (tab)
	{
		while (index < i)
		{
			free(tab[index]);
			index++;
		}
	}
}

int		writer(t_list *list, t_data *data)
{
	char	**tab;
	t_list	*tmp;
	float	y;
	int		i;

	y = 0.0;
	i = 0;
	while (list)
	{
		tab = ft_strsplit((char *)list->content, ' ');
		while (tab[i])
			i++;
		if (y > 0 && data->nombre_x != i)
			return (-1);
		data->nombre_x = i;
		(data->tab_int)[(int)y] = i;
		if (!((((*data).board)[(int)y]) = malloc(sizeof(t_board) * i)))
			return (-1);
		put_in(i, tab, y, data);
		if (y < data->index)
			ft_free(tab, i);
		y += 1.0;
		tmp = list;
		list = list->next;
		free(tmp->content);
		free(tmp);
	}
	makes_my_grid(data);
	return (0);
}

int		my_parser(char *argc, t_data *data, t_list *list, int fd)
{
	char			*line;
	int				ret;
	char 			*tmp;

	line = NULL;
	list = NULL;
	data->index = 0;
	if ((fd = open(argc, O_RDONLY)) < 0)
		return (-1);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		tmp = line;
		if (ret == -1 && list == NULL)
			return (-1);
		ft_add_end(&list, ft_lstnew(line, (sizeof(char) * (ft_strlen(line)
		+ 1))));
		if ((checker_norm(line)) == -1)
			return (-1);
		data->index++;
		free(tmp);
	}
	if (!(data->board = malloc(sizeof(t_board) * data->index)))
		return (-1);
	if (!(data->tab_int = malloc(sizeof(int) * data->index)))
		return (-1);
	if (writer(list, data) != 0)
		return (-1);
	return (0);
}
