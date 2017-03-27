/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:33:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 10:28:42 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printetc(char *flag, t_nl *ls, int *len)
{
	struct passwd	*pw;
	struct group	*gr;

	gr = getgrgid(ls->statis.st_gid);
	pw = getpwuid(ls->statis.st_uid);
	ft_putstr(" ");
	ft_putlennbr(len[0], ls->statis.st_nlink);
	ft_putchar(' ');
	if (!ft_strchr(flag, 'g'))
	{
		ft_putlenstr(len[1], pw ? pw->pw_name : NULL);
		ft_putstr("  ");
	}
	ft_putlenstr(len[2], gr ? gr->gr_name : NULL);
	ft_putchar(' ');
	if (!S_ISCHR(ls->statis.st_mode) && !S_ISBLK(ls->statis.st_mode))
		ft_putlennbr(len[3], ls->statis.st_size);
	else
	{
		ft_putlennbr(len[3] - 5, major(ls->statis.st_rdev));
		ft_putchar(',');
		ft_putlennbr(4, minor(ls->statis.st_rdev));
	}
}

void	ft_printstat(char *flag, t_nl *ls, int *len)
{
	ft_printmode(ls->statis);
	ft_printacl(ls->dinl);
	ft_printetc(flag, ls, len);
	ft_printtime(ls);
}

void	ft_printls(char *flag, t_nl *res, char *path, int *len)
{
	if (ft_strcmp(res->dinl, ""))
	{
		ft_strchr(flag, 's') ? ft_printblks(res->statis, len) : 0;
		ft_strchr(flag, 'l') || ft_strchr(flag, 'g') ?
		ft_printstat(flag, res, len) : 0;
		ft_strchr(flag, 'G') ? ft_printcolor(res) : 0;
		if (ft_strchr(flag, 'd'))
			ft_putstr(res->dinl);
		else
			ft_putstr(res->dinl + (!ft_strcmp(path, "/") ? 1 :
			ft_strlen(path)));
		ft_putstr("\033[0m");
		(ft_strchr(flag, 'l') || ft_strchr(flag, 'g')) &&
		S_ISLNK(res->statis.st_mode) ? ft_printlnk(res) : 0;
		res->dir == 1 ? ft_putendl("/") : ft_putchar('\n');
	}
}
