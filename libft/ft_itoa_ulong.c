/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:10:16 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 13:10:17 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

char	*ft_itoa_ulong(unsigned long n, int base)
{
	unsigned	long	stock;
	int					count;
	char				*tab;

	if (base <= 0)
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(char) * (ft_intlen(n, 10) + 2))))
		return (NULL);
	stock = n;
	count = ft_uintlen(n, base) - 1;
	if (stock == 0)
		tab[0] = '0';
	while (stock != 0)
	{
		tab[count] = ((stock % base) + 48);
		if (tab[count] > 57)
			tab[count] += 39;
		stock = stock / base;
		count--;
	}
	return (tab);
}
