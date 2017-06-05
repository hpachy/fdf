/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 17:07:59 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/27 12:27:51 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i != (int)size)
	{
		tab[i] = '\0';
		i++;
	}
	tab[i] = '\0';
	return (tab);
}
