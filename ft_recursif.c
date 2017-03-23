/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:18:59 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/23 00:25:24 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_addsubdir(char *flag, t_nl *subdir, char *path, struct dirent *entry)
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

void	ft_recursif(char *flag, t_nl *root, int *boole)
{
	struct dirent	*entry;
	DIR				*dp;
	t_nl			*subdir;
	t_nl			*file;
	char			*path;

	subdir = NULL;
	file = NULL;
	path = !ft_strcmp(root->dinl, "/") ? ft_strdup(root->dinl) : ft_strcjoin(root->dinl, '/');
	*boole ? ft_printf("\n%s:\n", root->dinl) : 0;
	*boole = 1;
	if ((dp = opendir(root->dinl)))
	{
		while (dp && (entry = readdir(dp)))
		{
			if (ft_strchr(flag, 'a') || entry->d_name[0] != '.')
				file = ft_addsubdir(flag, file, path, entry);
			if (ft_strchr(flag, 'R') && ft_testdir(entry, path))	
				subdir = ft_addsubdir(flag, subdir, path, entry);
		}
		closedir(dp);
		file = ft_sort(flag, file);
		ft_printall(flag, file, path);
		subdir = ft_sort(flag, subdir);
	}
	else
		ft_error(root->dinl);
	free(path);
	while (subdir)
	{
		ft_recursif(flag, subdir, boole);
		free(subdir->dinl);
		free(subdir);
		subdir = subdir->next;
	}
}
