/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/09 20:44:10 by pbourlet         ###   ########.fr       */
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
		(entry->d_name[0] == '.' && ft_strchr(flag, 'a')) ||
		entry->d_name[0] != '.' ? (str->dinl = ft_strjoinf(str->dinl, "/")) : 0;
	}
	(entry->d_name[0] == '.' && ft_strchr(flag, 'a')) ||
	entry->d_name[0] != '.' ? (str->dinl = ft_strjoinf(str->dinl, "\n")) : 0;
	if (str->next)
		str = str->next;
	return (str);
}

char	*ft_path(t_nl *root, int boole)
{
	char *str;

	str = NULL;
	root->next || (!root->next && boole) ?
	(str = ft_strjoinf(str, root->dinl)) : 0;
	root->next || (!root->next && boole) ?
	(str = ft_strjoinf(str, ":\n")) : 0;
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

t_nl	*ft_ls(t_nl *str, char *flag, t_nl *root)
{
	struct dirent	*entry;
	DIR				*dp;
	t_nl			*begin;
	int				boole;
	t_nl			*res;

	begin = root;
	while (root && root->dinl)
	{
		str = ft_strinit(str, root, boole);
		boole != 1 ? (res = str) : 0;
		if ((dp = opendir(root->dinl)) == NULL)
		{
			ft_putstr("ft_ls: ");
			perror(root->dinl);
			return (NULL);
		}
		while ((entry = readdir(dp)))
			str = ft_lsstock(str, entry, flag, root);
		root->next ? (str->dinl = ft_strjoinf(str->dinl, "\n")) : 0;
		closedir(dp);
		boole = 1;
		root = root->next;
	}
	return (res);
}
