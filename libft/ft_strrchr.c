/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 15:18:52 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/05 15:18:54 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen((char*)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char*)s + (i));
		i--;
	}
	if ((char)c == '\0')
		return ((char*)s + (i));
	return (NULL);
}
