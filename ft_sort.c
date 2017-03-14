/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:45:08 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/14 18:48:23 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_sort(char *flag, t_nl *list)
{
	t_nl *ls[5];

	if (!list || !list->next)
		return (list);
	ls[0] = list;
	ls[1] = list;
	ls[2] = list;
	ls[3] = list;
	while (ls[0])
	{
		if (ft_strchr(flag, 'r') ? ft_strcmp(ls[0]->dinl, ls[1]->dinl) > 0 :
		ft_strcmp(ls[0]->dinl, ls[1]->dinl) < 0)
		{
			ls[3] = ls[2];
			ls[1] = ls[0];
		}
		ls[2] = ls[0];
		ls[0] = ls[0]->next;
	}
	if (ls[1] != list)
	{
		ls[3]->next = list;
		ls[4] = list->next;
		list->next = ls[1]->next;
		ls[1]->next = ls[4];
	}
	ls[1]->next = ft_sort(flag, ls[1]->next);
	return (ls[1]);
}
