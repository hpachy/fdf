/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:40:25 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 16:40:27 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	int		i;
	size_t	*tab;

	i = 0;
	tab = malloc(sizeof(size_t) * size);
	if (tab == NULL)
		return (NULL);
	while (i != (int)size)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
