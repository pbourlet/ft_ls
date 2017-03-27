/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:46:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 10:46:29 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_testfc(t_nl **ls, int *boole)
{
	perror(ls[3]->dinl);
	free(ls[3]->dinl);
	if (ls[1] == NULL)
		ls[0] = ls[3]->next;
	else
		ls[1]->next = ls[3]->next;
	ls[2] = ls[3];
	ls[3] = ls[3]->next;
	free(ls[2]);
	*boole = 1;
	return (ls[3]);
}

t_nl	*ft_isdir(t_nl *list)
{
	DIR				*dp;
	t_nl			*ls[4];
	int				boole;
	struct stat		statis;

	ls[0] = list;
	ls[3] = list;
	ls[1] = NULL;
	while (ls[3])
	{
		if ((dp = opendir(ls[3]->dinl)) == NULL &&
				(stat(ls[3]->dinl, &statis) < 0))
			ls[3] = ft_testfc(ls, &boole);
		else
		{
			ls[3]->dir = ls[3]->next || boole == 1 ? 2 : 0;
			dp ? closedir(dp) : 0;
			ls[1] = ls[3];
			ls[3] = ls[3]->next;
		}
	}
	return (ls[0]);
}
