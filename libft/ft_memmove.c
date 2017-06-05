/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 10:07:34 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/09 10:07:35 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = dst - src;
	if (i > 0)
	{
		while ((int)len-- > 0)
			((char *)dst)[len] = ((char *)src)[len];
		return (dst);
	}
	return (ft_memcpy(dst, src, (int)len));
}
