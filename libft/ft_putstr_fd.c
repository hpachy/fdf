/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 14:55:37 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 14:55:39 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int a;

	a = 0;
	if (((char)s))
	{
		while (s[a] != '\0')
		{
			ft_putchar_fd(s[a], fd);
			a++;
		}
	}
	else
		ft_putchar_fd('\0', fd);
}
