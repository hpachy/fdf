/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:12:45 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/09 17:20:50 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strstr(const char *big, const char *little)
{
	int n;
	int i;
	int	save;

	save = 0;
	i = 0;
	n = 0;
	if (little[n] == '\0')
		return ((char*)big);
	while (big[i] != '\0')
	{
		while (big[i] == little[n] && little[n] != '\0')
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
