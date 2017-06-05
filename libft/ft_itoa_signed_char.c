/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_signed_char.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 11:21:48 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 11:21:48 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "libft.h"

static	int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

char		*ft_itoa_signed_char(signed char n)
{
	signed	char	stock;
	int				count;
	char			*tab;

	if (!(tab = ft_memalloc(sizeof(char) * (ft_intlen(n, 10) + 2))))
		return (NULL);
	stock = n;
	count = ft_uintlen(ft_abs(n), 10) - 1;
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
