/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:51:18 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/05 17:51:22 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

void	*ft_memccpy(void *restrict dst,
	const void *restrict src, int c, size_t n)
{
	int i;

	i = 0;
	while (i < (int)n)
	{
		((char *)dst)[i] = ((char *)src)[i];
		if ((unsigned char)c == ((unsigned char *)src)[i])
			return ((char*)dst + (i + 1));
		i++;
	}
	return (NULL);
}
