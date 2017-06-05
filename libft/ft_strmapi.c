/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:54:35 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 10:54:36 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	char			*str;

	len = 0;
	if (s)
	{
		while (s[len])
			len++;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		len = 0;
		while (s[len])
		{
			str[len] = f((unsigned int)len, s[len]);
			len++;
		}
		str[len] = '\0';
		return (str);
	}
	return (NULL);
}
