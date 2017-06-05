/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 12:21:20 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/05 12:21:22 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int i;
	int n;
	int	save;

	save = 0;
	i = 0;
	n = 0;
	if (little[n] == '\0')
		return ((char*)big);
	while (big[i] != '\0' && i != (int)len)
	{
		while (big[i] == little[n] && i != (int)len && little[n] != '\0')
		{
			i++;
			n++;
		}
		if (little[n] == '\0')
			return ((char*)big + (i - n));
		if (little[n] != '\0')
		{
			n = 0;
			i = save++;
		}
	}
	return (NULL);
}
