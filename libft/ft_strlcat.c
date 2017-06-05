/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 11:56:45 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/09 14:31:48 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dest;
	const char	*srcbis;
	size_t		n;
	size_t		dlen;

	dest = dst;
	srcbis = src;
	n = size;
	while (n-- != 0 && *dest != '\0')
		dest++;
	dlen = dest - dst;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(srcbis));
	while (*srcbis != '\0')
	{
		if (n != 1)
		{
			*dest++ = *srcbis;
			n--;
		}
		srcbis++;
	}
	*dest = '\0';
	return (dlen + (srcbis - src));
}
