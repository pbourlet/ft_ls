/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:33:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/16 17:29:59 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printmode(struct stat st)
{
	S_ISBLK(st.st_mode) ? ft_putchar('b') : 0;
	S_ISCHR(st.st_mode) ? ft_putchar('c') : 0;
	S_ISFIFO(st.st_mode) ? ft_putchar('p') : 0;
	S_ISREG(st.st_mode) ? ft_putchar('-') : 0;
	S_ISDIR(st.st_mode) ? ft_putchar('d') : 0;
	S_ISLNK(st.st_mode) ? ft_putchar('l') : 0;
	S_ISSOCK(st.st_mode) ? ft_putchar('s') : 0;
	ft_putchar(S_IRUSR & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWUSR & st.st_mode ? 'w' : '-');
	ft_putchar(S_IXUSR & st.st_mode ? 'x' : '-');
	ft_putchar(S_IRGRP & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWGRP & st.st_mode ? 'w' : '-');
	ft_putchar(S_IXGRP & st.st_mode ? 'x' : '-');
	ft_putchar(S_IROTH & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWOTH & st.st_mode ? 'w' : '-');
	ft_putchar(S_IXOTH & st.st_mode ? 'x' : '-');
}

void	ft_sizemax(t_nl *ls, int *len)
{
	struct passwd	*pw;
	struct group	*gr;
	t_nl 	*cond;
	int		tmp[4];

	cond = ls;
	gr = getgrgid(ls->statis.st_gid);
	pw = getpwuid(ls->statis.st_uid);
	len[0] = 0;
	len[1] = 0;
	len[2] = 0;
	len[3] = 0;
	while (cond)
	{
		tmp[0] = ft_nblen(cond->statis.st_nlink);
		tmp[0] > len[0] ? len[0] = tmp[0] : 0;
		tmp[1] = ft_strlen(pw->pw_name);
		tmp[1] > len[1] ? len[1] = tmp[1] : 0;
		tmp[2] = ft_strlen(gr->gr_name);
		tmp[2] > len[2] ? len[2] = tmp[2] : 0;
		tmp[3] = ft_nblen(cond->statis.st_size);
		tmp[3] > len[3] ? len[3] = tmp[3] : 0;
		cond = cond->next;
	}
}

void	ft_printetc(t_nl *ls, int *len)
{
	struct passwd	*pw;
	struct group	*gr;

	gr = getgrgid(ls->statis.st_gid);
	pw = getpwuid(ls->statis.st_uid);
	ft_printf("  %*d", len[0], ls->statis.st_nlink);
	ft_printf(" %*s ", len[1], pw->pw_name);
	ft_printf(" %*s ", len[2], gr->gr_name);
	ft_printf(" %*lld ", len[3], ls->statis.st_size);
}

void	ft_printstat(t_nl *ls, int *len)
{
	ft_printmode(ls->statis);
	ft_printetc(ls, len);
	ft_printf(" %.12s ", ctime(&ls->statis.st_mtime) + 4);
}

void	ft_printls(char *flag, t_nl *res, DIR *dp, int *boole)
{
	int len[4];

	ft_strchr(flag, 'l') ? ft_sizemax(res, len) : 0;
	while (res)
	{
		if (ft_strcmp(res->dinl, ""))
		{
			ft_strchr(flag, 'l') ? ft_printstat(res, len) : 0;
			ft_putstr(res->dinl);
			res->dir == 1 ? ft_putendl("/") : ft_putchar('\n');
		}
		ft_strclr(res->dinl);
		free(res->dinl);
		free(res);
		res = res->next;
	}
	if (dp)
	{
		closedir(dp);
		*boole = 1;
	}
}
