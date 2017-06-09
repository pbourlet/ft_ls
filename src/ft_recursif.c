/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:18:59 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:58:29 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nl	*ft_add(char *flag, t_nl *subdir, char *path, struct dirent *entry)
{
	t_nl	*ls;

	if (!subdir)
		subdir = ft_nlcreate(flag, path, entry->d_name);
	else
	{
		ls = subdir;
		while (ls->next)
			ls = ls->next;
		ls->next = ft_nlcreate(flag, path, entry->d_name);
	}
	return (subdir);
}

void	ft_initrecursif(t_nl **fich, char **path, t_nl *root, int *boole)
{
	fich[0] = NULL;
	fich[1] = NULL;
	*path = !ft_strcmp(root->dinl, "/") ? ft_strdup(root->dinl) :
	ft_strcjoin(root->dinl, '/');
	*boole == 1 ? ft_printf("\n%s:\n", root->dinl) : 0;
	*boole = 1;
}

void	ft_suite(char *flag, t_nl *ls, int *boole)
{
	while (ls)
	{
		ft_recursif(flag, ls, boole);
		free(ls->dinl);
		free(ls);
		ls = ls->next;
	}
}

void	ft_recursif(char *flag, t_nl *root, int *boole)
{
	struct dirent	*entry;
	DIR				*dp;
	t_nl			*fich[2];
	char			*path;

	ft_initrecursif(fich, &path, root, boole);
	if ((dp = opendir(root->dinl)))
	{
		while ((entry = readdir(dp)))
		{
			if (ft_strchr(flag, 'a') || entry->d_name[0] != '.')
				fich[1] = ft_add(flag, fich[1], path, entry);
			if ((ft_strchr(flag, 'a') || entry->d_name[0] != '.') &&
			ft_strchr(flag, 'R') && ft_testdir(entry, path))
				fich[0] = ft_add(flag, fich[0], path, entry);
		}
		closedir(dp);
		fich[1] = ft_sort(flag, fich[1]);
		ft_printall(flag, fich[1], path);
		fich[0] = ft_sort(flag, fich[0]);
	}
	else
		ft_error(root->dinl);
	free(path);
	ft_suite(flag, fich[0], boole);
}
