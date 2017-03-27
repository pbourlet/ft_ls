/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:18:37 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 10:18:38 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_testdir(struct dirent *ent, char *path)
{
	struct stat	st;
	char		*name;

	if ((ent->d_type != DT_DIR && ent->d_type != DT_UNKNOWN)
	|| ft_strequ(ent->d_name, ".") || ft_strequ(ent->d_name, ".."))
		return (0);
	if (ent->d_type == DT_UNKNOWN)
	{
		name = ft_strcjoin(path, '/');
		name = ft_strjoinf(name, ent->d_name);
		if (lstat(name, &st) < 0)
		{
			ft_putstr("ft_ls: ");
			perror(name);
			ft_strdel(&name);
			return (0);
		}
		ft_strdel(&name);
		if (!S_ISDIR(st.st_mode))
			return (0);
	}
	return (1);
}
