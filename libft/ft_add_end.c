/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_end.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hpachy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:20:26 by abitoun           #+#    #+#             */
/*   Updated: 2016/11/10 15:20:52 by abitoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_add_end(t_list **begin_list, t_list *new)
{
	t_list	*save;

	if (new && begin_list)
	{
		save = *begin_list;
		if (!(*begin_list))
			*begin_list = new;
		else
		{
			while ((*begin_list)->next)
				(*begin_list) = (*begin_list)->next;
			(*begin_list)->next = new;
			new->next = NULL;
			(*begin_list) = save;
		}
	}
}
