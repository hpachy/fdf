/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_strnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:53:40 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/21 12:53:41 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_c_strnew(int size, char c)
{
	int		i;
	char	*tab;

	i = 0;
	if (!(tab = ft_memalloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i <= size)
	{
		tab[i] = 0;
		i++;
	}
	i = 0;
	while (i < size)
	{
		tab[i] = c;
		i++;
	}
	return (tab);
}
