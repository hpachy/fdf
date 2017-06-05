/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 17:16:51 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/10 17:16:54 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(intmax_t c, int base)
{
	int			nb_division;

	nb_division = 0;
	if (c == 0)
		nb_division++;
	while (c)
	{
		nb_division++;
		c = c / base;
	}
	return (nb_division);
}
