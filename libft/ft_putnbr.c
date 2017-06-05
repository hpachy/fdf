/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 13:20:34 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 13:53:10 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(int n)
{
	char		tab[19];
	int			i;
	long int	stock;

	i = 0;
	stock = n;
	if (stock < 0)
	{
		stock = stock * (-1);
		ft_putchar('-');
	}
	while (stock >= 10)
	{
		tab[i] = ((stock % 10) + 48);
		stock = stock / 10;
		i++;
	}
	if (stock < 10)
		tab[i] = (stock + 48);
	while (i >= 0)
	{
		ft_putchar(tab[i]);
		i--;
	}
}
