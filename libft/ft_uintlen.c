/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 10:11:28 by hpachy            #+#    #+#             */
/*   Updated: 2017/05/09 10:11:28 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_uintlen(uintmax_t c, int base)
{
	int			nb_division;
	uintmax_t	stock;

	stock = c;
	nb_division = 0;
	if (c == 0)
		nb_division++;
	while (stock)
	{
		nb_division++;
		stock = stock / base;
	}
	return (nb_division);
}
