/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 18:29:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/24 23:09:04 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_testfile(t_nl **ls, int *len, char *flag)
{
	ft_printls(flag, ls[3], NULL, len);
	free(ls[3]->dinl);
	if (ls[1] == NULL)
		ls[0] = ls[3]->next;
	else
		ls[1]->next = ls[3]->next;
	ls[2] = ls[3];
	ls[3] = ls[3]->next;
	free(ls[2]);
	len[7] = 1;
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
	len[7] = 0;
	ls[1] = NULL;
	ft_strchr(flag, 's') || ft_strchr(flag, 'd') || ft_strchr(flag, 'l')
	|| ft_strchr(flag, 'g') ? ft_sizemax(flag, ls[3], len) : 0;
	while (ls[3])
	{
		if (ft_strchr(flag, 'd') || ((dp = opendir(ls[3]->dinl))
		== NULL && lstat(ls[3]->dinl, &st) >= 0))
			ls[3] = ft_testfile(ls, len, flag);
		else
		{
			dp ? closedir(dp) : 0;
			ls[1] = ls[3];
			ls[3] = ls[3]->next;
		}
	}
	ls[0] && len[7] ? ft_putchar('\n') : 0;
	return (ls[0]);
}
