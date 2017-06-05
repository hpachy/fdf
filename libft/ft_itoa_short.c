/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:10:21 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 11:10:23 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_short(short int n)
{
	short	int		stock;
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
