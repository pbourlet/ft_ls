/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/15 19:02:01 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_lsstock(t_nl *str, struct dirent *entry, char *flag, t_nl *root)
{
	if (entry->d_name[0] != '.' || ft_strchr(flag, 'a'))
		str->next = ft_nlcreate(flag, root->dinl, entry->d_name);
	if (entry->d_type == DT_DIR)
	{
		if (ft_strchr(flag, 'R') && entry->d_name[0] != '.')
			root = ft_joinls(flag, root, root->dinl, entry->d_name);
		str->next ? str->next->dir = 1 : 0;
	}
	if (str->next)
		str = str->next;
	return (str);
}

int		ft_ls(t_nl *str, char *flag, t_nl *root)
{
	struct dirent	*entry;
	DIR				*dp;
	int				boole;
	t_nl			*res;

	while (root && root->dinl)
	{
		(boole != 1 && root->next) || root->dir == 2 ?
		ft_printf("%s:\n", root->dinl) : 0;
		boole == 1 ? ft_printf("\n%s:\n", root->dinl) : 0;
		if (!(boole != 1 && !root->dir))
		{
			if (!(root = ft_opentestls(&dp, root, boole)))
				return (1);
		}
		str = ft_nlcreate(flag, "", "");
		res = str;
		while (dp && (entry = readdir(dp)))
			str = ft_lsstock(str, entry, flag, root);
		res = ft_sort(flag, res);
		ft_printls(flag, res, dp, &boole);
		free(root->dinl);
		free(root);
		root = root->next;
		ft_strchr(flag, 'r') ? root = ft_sort(flag, root) : 0;
	}
	return (0);
}
