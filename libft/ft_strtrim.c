/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:46:25 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/07 15:46:26 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		end;
	int		start;
	char	*tmp;

	start = 0;
	if (s == NULL)
		return (NULL);
	end = ft_strlen(s);
	while (s[end] == '\0' || s[end] == '\n' || s[end] == '\t' || s[end] == ' ')
		end--;
	while (s[start] == '\0' || s[start] == '\n' ||
			s[start] == '\t' || s[start] == ' ')
		start++;
	tmp = malloc(sizeof(char) * (end - start + 1));
	ft_strncpy(tmp, s + start, end - start + 1);
	return (tmp);
}
