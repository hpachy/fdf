/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 15:02:58 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/04 15:03:00 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int w;
	int i;
	int negatif;

	negatif = 0;
	i = 0;
	w = 0;
	str = ft_isspace((char *)str);
	if (str[i] == '-')
	{
		negatif = 1;
		i++;
	}
	if (str[i] == '+' && negatif == 0)
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		w = w * 10;
		w = w + str[i] - 48;
		i++;
	}
	if (negatif == 1)
		return (-w);
	return (w);
}
