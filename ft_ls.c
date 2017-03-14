/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/14 19:06:39 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_lsstock(t_nl *str, struct dirent *entry, char *flag, t_nl *root)
{
	if (entry->d_name[0] != '.' || ft_strchr(flag, 'a'))
		str->next = ft_nlcreate(entry->d_name);
	if (entry->d_type == DT_DIR)
	{
		if (ft_strchr(flag, 'R') && entry->d_name[0] != '.')
			root = ft_joinls(root, root->dinl, entry->d_name);
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
		boole != 1 && root->next ? ft_printf("%s:\n", root->dinl) : 0;
		boole == 1 ? ft_printf("\n%s:\n", root->dinl) : 0;
		if (!(root = ft_opentestls(&dp, root, boole)))
			return (-1);
		str = ft_nlcreate("");
		res = str;
		while ((entry = readdir(dp)))
			str = ft_lsstock(str, entry, flag, root);
		res = ft_sort(flag, res);
		root = ft_printls(res, root);
		closedir(dp);
		boole = 1;
	}
	return (1);
}
