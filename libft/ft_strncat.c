/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 12:07:07 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/04 12:07:13 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s1[count] != '\0')
		count++;
	while (s2[i] != '\0' && i != (int)n)
	{
		s1[count] = s2[i];
		count++;
		i++;
	}
	s1[count] = '\0';
	return (s1);
}
