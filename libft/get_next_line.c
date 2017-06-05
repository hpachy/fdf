/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 10:14:30 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/30 12:28:41 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		check(char *str)
{
	int n;

	n = 0;
	while (str[n])
	{
		if (str[n] == '\n')
			return (n);
		n++;
	}
	return (n);
}

int		reader(int fd, char **tab)
{
	char	*tmp;
	char	*str;
	char	buffer[BUFF_SIZE + 1];
	int		i;

	while (!(str = ft_strchr(*tab, '\n')) &&
		(i = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[i] = '\0';
		tmp = *tab;
		*tab = ft_strjoin(*tab, buffer);
		free(tmp);
	}
	if (i == -1)
		return (-1);
	if (i == 0 && !str)
		return (0);
	return (1);
}

int		fill_struct(t_list **list, int fd, char **line)
{
	t_data	data;
	char	*tmp;
	int		n;

	data.fd_stock = fd;
	data.buf = ft_strnew(1);
	if ((n = reader(fd, &data.buf)) == -1)
		return (-1);
	data.index = check(data.buf);
	tmp = *line;
	*line = ft_strsub(data.buf, 0, data.index);
	tmp = data.buf;
	if (n != 0)
		data.buf = ft_strdup(ft_strchr(data.buf, '\n') + 1);
	else
		data.buf = ft_strnew(1);
	free(tmp);
	ft_lstadd(list, ft_lstnew(&data, sizeof(data)));
	return (1);
}

int		next_line(t_list *list, int fd, char **line)
{
	int		n;
	char	*yolo;

	if ((n = reader(fd, &(TMPP->buf))) == -1)
		return (-1);
	if (n == 0)
	{
		*line = ft_strnew(1);
		yolo = *line;
		*line = ft_strjoin(*line, TMPP->buf);
		if (ft_strcmp(TMPP->buf, "") != 0)
			n = 1;
		free(yolo);
		yolo = TMPP->buf;
		TMPP->buf = ft_strnew(1);
		free(yolo);
		return (n);
	}
	TMPP->index = check(TMPP->buf);
	yolo = TMPP->buf;
	(*line) = ft_strsub(TMPP->buf, 0, TMPP->index);
	TMPP->buf = ft_strdup(ft_strchr(TMPP->buf, '\n') + 1);
	free(yolo);
	return (n);
}

int		get_next_line(const int fd, char **line)
{
	static	t_list	*list;
	t_list			*save;
	int				exist;
	int				n;

	exist = 0;
	save = list;
	if (fd < 0 || !line)
		return (-1);
	while (list)
	{
		if (((t_data *)list->content)->fd_stock == fd)
		{
			if ((n = next_line(list, fd, line)) == -1)
			{
				return (-1);
			}
			exist = 1;
		}
		list = list->next;
	}
	if (exist == 0)
		if ((n = fill_struct(&save, fd, line)) == -1)
			return (-1);
	ft_add_end(&list, save);
	return (n);
}
