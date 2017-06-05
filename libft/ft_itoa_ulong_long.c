/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ulong_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 13:01:37 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 13:01:38 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_ulong_long(unsigned long long n, int base)
{
	unsigned long long	stock;
	int					count;
	char				*tab;

	if (base <= 0)
		return (NULL);
	if (!(tab = ft_memalloc(sizeof(char) * (ft_uintlen(n, base) + 1))))
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
