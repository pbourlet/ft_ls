/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:11:06 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 21:11:10 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_ls	*ft_dir(t_ls *l, char *name)
{
	t_ls	*b;

	b = l;
	if (!l)
	{
		l = malloc(sizeof(char *) + sizeof(char *));
		l->path = name;
		l->next = NULL;
		return (l);
	}
	while (l->next)
		l = l->next;
	l->next = malloc(sizeof(char *) + sizeof(char *));
	l = l->next;
	l->path = name;
	l->next = NULL;
	return (b);
}

t_ls	*ft_lstck(int flag, t_ls *b)
{
	struct	dirent	*entry;
	DIR				*dp;
	t_ls			*l;

	l = NULL;
	dp = opendir(b->path);
	flag = flag + 1;
	if (dp == NULL)
		return (NULL);
	while ((entry = readdir(dp)))
	{
		if (entry->d_name[0] != '.')
		{
			if (entry->d_type == DT_DIR)
			{
				l = ft_dir(l, entry->d_name);
			}
		}
	}
	closedir(dp);
	return (l);
}
