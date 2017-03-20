/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:29:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/20 21:27:38 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_testfile(t_nl **ls, int *len, char *flag)
{
	if (ft_strchr(flag, 'l'))
		ft_printls("l", ls[3], ls[0], len);
	else
		ft_putendl(ls[3]->dinl);
	free(ls[3]->dinl);
	if (ls[1] == NULL)
		ls[0] = ls[3]->next;
	else
		ls[1]->next = ls[3]->next;
	ls[2] = ls[3];
	ls[3] = ls[3]->next;
	free(ls[2]);
	len[4] = 1;
	return (ls[3]);
}

t_nl	*ft_isfile(char *flag, t_nl *list)
{
	DIR				*dp;
	t_nl			*ls[4];
	int				len[FORMAT_SIZE + 2];
	struct stat		st;

	ls[0] = list;
	ls[3] = list;
	ls[1] = NULL;
	while ((len[6] = list->dir == 2 ? 2 : 3) && ls[3])
	{
		if ((dp = opendir(ls[3]->dinl)) == NULL && stat(ls[3]->dinl, &st) >= 0)
		{
			ft_strchr(flag, 'l') ? ft_sizemax(ls[3], len) : 0;
			ls[3] = ft_testfile(ls, len, flag);
		}
		else
		{
			ls[3]->dir = len[6] == 2 || ls[3]->next || len[5] == 1 ? 2 : 1;
			dp ? closedir(dp) : 0;
			ls[1] = ls[3];
			ls[3] = ls[3]->next;
		}
	}
	ls[0] && len[5] == 1 ? ft_putchar('\n') : 0;
	return (ls[0]);
}
