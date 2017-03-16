/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:22:15 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/16 12:38:22 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_testfc(t_nl *list, t_nl **ls, int *boole)
{
	struct stat		statis;

	if (stat(list->dinl, &statis) < 0)
		perror(list->dinl);
	else
		ft_putendl(list->dinl);
	free(list->dinl);
	if (ls[1] == NULL)
		ls[0] = list->next;
	else
		ls[1]->next = list->next;
	ls[2] = list;
	list = list->next;
	free(ls[2]);
	*boole = 1;
	return (list);
}

t_nl	*ft_isdir(t_nl *list)
{
	DIR				*dp;
	t_nl			*ls[3];
	int				boole;

	ls[0] = list;
	ls[1] = NULL;
	while (list)
	{
		if ((dp = opendir(list->dinl)) == NULL)
			list = ft_testfc(list, ls, &boole);
		else
		{
			list->dir = list->next || boole == 1 ? 2 : 1;
			closedir(dp);
			ls[1] = list;
			list = list->next;
		}
	}
	ls[0] && boole == 1 ? ft_putchar('\n') : 0;
	return (ls[0]);
}
