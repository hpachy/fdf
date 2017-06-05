/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 11:33:37 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 11:33:38 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	static	*ft_strncopy(char *dst, const char *src, size_t len)
{
	unsigned int c;

	c = 0;
	while (src[c] != '\0' && (c < len))
	{
		dst[c] = src[c];
		c++;
	}
	dst[c] = '\0';
	return (dst);
}

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		n;
	char	*str;

	n = (int)len;
	str = malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	if (s == NULL)
		return (NULL);
	return (ft_strncopy(str, s + start, (unsigned int)len));
}
