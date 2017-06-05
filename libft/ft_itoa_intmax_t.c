/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_intmax_t.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:04:51 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/26 15:04:52 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_intmax_t(intmax_t n)
{
	intmax_t		stock;
	int				count;
	char			*tab;

	if (!(tab = ft_memalloc(sizeof(char) * (ft_intlen(n, 10) + 2))))
		return (NULL);
	stock = n;
	count = ft_uintlen(n, 10) - 1;
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
