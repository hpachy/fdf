/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 15:12:03 by hpachy            #+#    #+#             */
/*   Updated: 2017/04/26 15:12:05 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_long_long(long long int n)
{
	long	long	int	stock;
	int					count;
	char				*tab;

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
