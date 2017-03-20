/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:33:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/20 21:15:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printetc(t_nl *ls, int *len)
{
	struct passwd	*pw;
	struct group	*gr;

	gr = getgrgid(ls->statis.st_gid);
	pw = getpwuid(ls->statis.st_uid);
	ft_putstr(" ");
	ft_putlennbr(len[0], ls->statis.st_nlink);
	ft_putchar(' ');
	ft_putlenstr(len[1], pw->pw_name);
	ft_putstr("  ");
	ft_putlenstr(len[2], gr->gr_name);
	ft_putchar(' ');
	if (!S_ISCHR(ls->statis.st_mode) && !S_ISBLK(ls->statis.st_mode))
		ft_putlennbr(len[3] + 1, ls->statis.st_size);
	else
	{
		ft_putlennbr(len[3] - 5, major(ls->statis.st_rdev));
		ft_putchar(',');
		ft_putlennbr(4, minor(ls->statis.st_rdev));
	}
}

void	ft_printstat(t_nl *ls, t_nl *root, int *len)
{
	ft_printmode(ls->statis);
	ft_printacl(ls->dinl, root->dinl);
	ft_printetc(ls, len);
	ft_printf(" %.12s ", ctime(&ls->statis.st_mtime) + 4);
}

void	ft_printls(char *flag, t_nl *res, t_nl *root, int *len)
{
	if (ft_strcmp(res->dinl, ""))
	{
		ft_strchr(flag, 'l') ? ft_printstat(res, root, len) : 0;
		ft_putstr(res->dinl);
		res->dir == 1 ? ft_putendl("/") : ft_putchar('\n');
	}
}
