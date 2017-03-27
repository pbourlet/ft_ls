/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizemax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:11:55 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 10:23:44 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		*ft_initlen(int *len)
{
	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
	len[4] = 0;
	len[5] = 0;
	return (len);
}

void	ft_sizemax(char *flag, t_nl *cond, int *len)
{
	struct passwd	*pw;
	struct group	*gr;
	int				tmp[FORMAT_SIZE];

	len = ft_initlen(len);
	while (cond)
	{
		gr = getgrgid(cond->statis.st_gid);
		pw = getpwuid(cond->statis.st_uid);
		tmp[0] = ft_nblen(cond->statis.st_nlink);
		tmp[0] > len[0] ? len[0] = tmp[0] : 0;
		!ft_strchr(flag, 'g') && pw ? tmp[1] = ft_strlen(pw->pw_name) : 0;
		!ft_strchr(flag, 'g') && pw && tmp[1] > len[1] ? len[1] = tmp[1] : 0;
		tmp[2] = gr ? ft_strlen(gr->gr_name) : 0;
		tmp[2] > len[2] ? len[2] = tmp[2] : 0;
		tmp[3] = !S_ISCHR(cond->statis.st_mode) &&
		!S_ISBLK(cond->statis.st_mode) ? ft_nblen(cond->statis.st_size) : 9;
		tmp[3] > len[3] ? len[3] = tmp[3] : 0;
		len[4] += cond->statis.st_blocks;
		tmp[5] = ft_nblen(cond->statis.st_blocks);
		tmp[5] > len[5] ? len[5] = tmp[5] : 0;
		cond = cond->next;
	}
}
