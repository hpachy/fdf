/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:24:38 by abitoun           #+#    #+#             */
/*   Updated: 2016/11/08 15:47:50 by abitoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static	int		ft_counterwords(char *str, char c)
{
	int count;
	int checker;

	checker = 0;
	count = 0;
	while (str[checker])
	{
		while (str[checker] == c && str[checker] != '\0')
			checker++;
		if (str[checker] != c && str[checker] != '\0')
			count++;
		while (str[checker] != c && str[checker] != '\0')
			checker++;
	}
	return (count);
}

static	int		ft_count_sizeword(char *str, char c)
{
	int n;
	int start;
	int end;

	n = 0;
	end = 0;
	while (str[n] == c && str[n] != '\0')
		n++;
	if (str[n] != c && str[n] != '\0')
		start = n;
	while (str[n] != c && str[n] != '\0')
		n++;
	if (str[n] == c || str[n] == '\0')
		end = n;
	return (end - start);
}

static	int		ft_count_pointer(char *str, char c)
{
	int n;
	int start;
	int end;

	n = 0;
	end = 0;
	while (str[n] == c && str[n] != '\0')
		n++;
	if (str[n] != c && str[n] != '\0')
		start = n;
	while (str[n] != c && str[n] != '\0')
		n++;
	if (str[n] == c || str[n] == '\0')
		end = n;
	return (end);
}

char			**ft_strsplit(char const *s, char c)
{
	int		n;
	int		nb_mot;
	int		taille_mot;
	int		pointer;
	char	**tab;

	pointer = 0;
	if ((!s))
		return (NULL);
	nb_mot = ft_counterwords((char *)s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * nb_mot + 1)))
		return (NULL);
	n = 0;
	while (nb_mot-- > 0)
	{
		while (s[pointer] == c)
			pointer++;
		taille_mot = ft_count_sizeword((char *)s + pointer, c);
		tab[n++] = ft_strsub(s, pointer, taille_mot);
		pointer += ft_count_pointer((char *)s + pointer, c);
	}
	tab[n] = NULL;
	return (tab);
}
