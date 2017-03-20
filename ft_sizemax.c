/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:11:55 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/20 21:35:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_sizemax(t_nl *cond, int *len)
{
	struct passwd	*pw;
	struct group	*gr;
	int				tmp[FORMAT_SIZE];

	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
	len[4] = 0;
	while (cond)
	{
		gr = getgrgid(cond->statis.st_gid);
		pw = getpwuid(cond->statis.st_uid);
		tmp[0] = ft_nblen(cond->statis.st_nlink);
		tmp[0] > len[0] ? len[0] = tmp[0] : 0;
		tmp[1] = ft_strlen(pw->pw_name);
		tmp[1] > len[1] ? len[1] = tmp[1] : 0;
		tmp[2] = ft_strlen(gr->gr_name);
		tmp[2] > len[2] ? len[2] = tmp[2] : 0;
		tmp[3] = !S_ISCHR(cond->statis.st_mode) &&
		!S_ISBLK(cond->statis.st_mode) ? ft_nblen(cond->statis.st_size) : 9;
		tmp[3] > len[3] ? len[3] = tmp[3] : 0;
		len[4] += cond->statis.st_blocks;
		cond = cond->next;
	}
}
