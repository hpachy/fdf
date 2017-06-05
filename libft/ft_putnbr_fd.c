/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:29:24 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 14:29:26 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char		tab[19];
	int			i;
	long int	stock;

	i = 0;
	stock = n;
	if (stock < 0)
	{
		stock = stock * (-1);
		ft_putchar_fd('-', fd);
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
		ft_putchar_fd(tab[i], fd);
		i--;
	}
}
