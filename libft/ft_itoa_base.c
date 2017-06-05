/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:29:25 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/18 17:29:27 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(uintmax_t nb, int base)
{
	uintmax_t	stock;
	int			count;
	char		*tab;

	if (base <= 0)
		return (NULL);
	stock = nb;
	count = ft_uintlen(nb, base) - 1;
	if (!(tab = ft_memalloc(sizeof(char) * (count + 2))))
		return (NULL);
	if (base < 2)
		return (NULL);
	if (stock == 0)
		tab[0] = '0';
	while (stock)
	{
		tab[count] = ((stock % base) + 48);
		if (tab[count] > '9')
			tab[count] += 39;
		stock = stock / base;
		count--;
	}
	return (tab);
}
