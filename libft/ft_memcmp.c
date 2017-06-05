/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 14:53:29 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 14:53:31 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int c;
	int stock;

	c = 0;
	stock = 0;
	while (c < (int)n)
	{
		if (((unsigned char *)s1)[c] == ((unsigned char *)s2)[c])
			c++;
		else
			return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
	}
	return (0);
}
