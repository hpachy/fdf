/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 14:36:30 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/28 14:36:31 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_size(size_t nb, int base)
{
	size_t	stock;
	int		count;
	char	*tab;

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
