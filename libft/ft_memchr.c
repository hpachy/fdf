/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 11:44:59 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 11:45:00 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		if ((unsigned char)c == ((unsigned char *)s)[i])
			return ((unsigned char*)s + i);
		i++;
	}
	return (NULL);
}
