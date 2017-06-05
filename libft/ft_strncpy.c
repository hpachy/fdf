/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 10:39:20 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/04 10:39:22 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*save;

	save = dst;
	while (len)
	{
		if (*src)
			*dst = *src++;
		else
			*dst = '\0';
		--len;
		++dst;
	}
	return (save);
}
