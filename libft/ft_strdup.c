/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 12:04:28 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/03 18:46:41 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	int		nb;
	int		n;

	n = 0;
	nb = ft_strlen(src);
	str = malloc(sizeof(char) * (nb + 1));
	if (str == NULL)
	{
		return (0);
	}
	while (src[n] != '\0')
	{
		str[n] = src[n];
		n++;
	}
	str[n] = '\0';
	return (str);
}
