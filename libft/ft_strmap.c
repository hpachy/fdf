/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 10:31:19 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 10:31:20 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		len;

	len = 0;
	if (((char*)s))
	{
		while (s[len])
			len++;
		str = malloc(sizeof(char) * (len + 1));
		if (str == NULL)
			return (NULL);
		len = 0;
		while (s[len])
		{
			str[len] = f(s[len]);
			len++;
		}
		str[len] = '\0';
		return ((char *)str);
	}
	return (NULL);
}
