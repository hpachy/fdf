/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 16:20:03 by hpachy            #+#    #+#             */
/*   Updated: 2016/11/06 16:20:04 by hpachy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	int a;

	a = 0;
	if (s)
	{
		while (s[a] != '\0')
		{
			ft_putchar_fd(s[a], fd);
			a++;
		}
	}
	if (!(s))
		ft_putchar_fd('\0', fd);
	ft_putchar_fd('\n', fd);
}
