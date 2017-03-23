/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:45:08 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/22 14:49:12 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ordre(char *flag, t_nl **ls)
{
	int res;

	res = 0;
	if (ft_strchr(flag, 'S'))
	{
		if (ft_strchr(flag, 'r'))
			    res = ls[0]->statis.st_size < ls[1]->statis.st_size ? 1 : 0;
		else
			    res = ls[0]->statis.st_size > ls[1]->statis.st_size ? 1 : 0;
		if (ls[0]->statis.st_size == ls[1]->statis.st_size)
		{
			if (ft_strchr(flag, 'r'))
				res = ft_strcmp(ls[0]->dinl, ls[1]->dinl) > 0 ? 1 : 0;
			else
				res = ft_strcmp(ls[0]->dinl, ls[1]->dinl) < 0 ? 1 : 0;
		}
	}
	else if (ft_strchr(flag, 't'))
	{
		if (ft_strchr(flag, 'r'))
			res = ls[0]->statis.st_mtime < ls[1]->statis.st_mtime ? 1 : 0;
		else
			res = ls[0]->statis.st_mtime > ls[1]->statis.st_mtime ? 1 : 0;
		if (ls[0]->statis.st_mtime == ls[1]->statis.st_mtime)
		{
			if (ft_strchr(flag, 'r'))
				res = ft_strcmp(ls[0]->dinl, ls[1]->dinl) > 0 ? 1 : 0;
			else
				res = ft_strcmp(ls[0]->dinl, ls[1]->dinl) < 0 ? 1 : 0;
		}
	}
	else
	{
		if (ft_strchr(flag, 'r'))
			res = ft_strcmp(ls[0]->dinl, ls[1]->dinl) > 0 ? 1 : 0;
		else
			res = ft_strcmp(ls[0]->dinl, ls[1]->dinl) < 0 ? 1 : 0;
	}
	return (res);
}

void	ft_initsort(t_nl **ls, t_nl *list)
{
	ls[0] = list;
	ls[1] = list;
	ls[2] = list;
	ls[3] = list;
}

t_nl	*ft_sort(char *flag, t_nl *list)
{
	t_nl *ls[5];

	if (!list || !list->next)
		return (list);
	ft_initsort(ls, list);
	while (ls[0])
	{
		if (ft_ordre(flag, ls))
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
