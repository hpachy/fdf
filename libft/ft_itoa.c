/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:18:56 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/08 19:13:58 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa(int n)
{
	int				stock;
	int				count;
	char			*tab;

	if (!(tab = ft_memalloc(sizeof(char) * (ft_intlen(n, 10) + 2))))
		return (NULL);
	stock = n;
	count = ft_intlen(n, 10) - 1;
	if (stock < 0)
	{
		count++;
		tab[0] = '-';
	}
	if (stock == 0)
		tab[0] = '0';
	while (stock != 0)
	{
		if (n < 0)
			tab[count] = ((stock % 10 * -1) + 48);
		else
			tab[count] = ((stock % 10) + 48);
		stock = stock / 10;
		count--;
	}
	return (tab);
}
