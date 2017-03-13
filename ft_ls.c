/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/13 15:17:57 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_lsstock(t_nl *str, struct dirent *entry, char *flag, t_nl *root)
{
	if (entry->d_name[0] == '.' && ft_strchr(flag, 'a'))
		str->next = ft_nlcreate(entry->d_name);
	else if (entry->d_name[0] != '.')
		str->next = ft_nlcreate(entry->d_name);
	if (entry->d_type == DT_DIR)
	{
		if (ft_strchr(flag, 'R') && entry->d_name[0] != '.')
			root = ft_joinls(root, root->dinl, entry->d_name);
//		(entry->d_name[0] == '.' && ft_strchr(flag, 'a')) ||
//		entry->d_name[0] != '.' ?
//		(str->next->dinl = ft_strjoinf(str->next->dinl, "/")) : 0;
	}
	if (str->next)
		str = str->next;
	return (str);
}

char	*ft_path(t_nl *root, int boole)
{
	char *str;

	str = NULL;
	if (boole != 1)
	{
		root->next ? (str = ft_strjoinf(str, root->dinl)) : 0;
		root->next ? (str = ft_strjoinf(str, ":")) : 0;
	}
	else if (root->next || (!root->next && boole))
	{
		root->next || (!root->next && boole) ?
		(str = ft_strjoinf(str, "\n")) : 0;
		root->next || (!root->next && boole) ?
		(str = ft_strjoinf(str, root->dinl)) : 0;
		root->next || (!root->next && boole) ?
		(str = ft_strjoinf(str, ":")) : 0;
	}
	return (str);
}

t_nl	*ft_strinit(t_nl *str, t_nl *root, int boole)
{
	if (boole != 1)
		str = ft_nlcreate(ft_path(root, boole) ? ft_path(root, boole) : "");
	else
	{
		str->next = ft_nlcreate(ft_path(root, boole));
		str = str->next;
	}
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
		if (!(root = ft_opentestls(&dp, root)))
			return (-1);
		str = ft_strinit(str, root, boole);
		res = str;
		while ((entry = readdir(dp)))
			str = ft_lsstock(str, entry, flag, root);
		res = ft_sort(flag, res);
		ft_printls(res);
		closedir(dp);
		boole = 1;
		root = root->next;
	}
	return (1);
}
