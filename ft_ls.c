/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/08 19:25:14 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls(int flag, t_nl *root)
{
	struct	dirent	*entry;
	DIR				*dp;
	t_nl			*begin;
	int				boole;

	(void)flag;
	begin = root;
	boole = 0;
	while (root && root->dinl)
	{
		ft_printf("\n%s:\n", root->dinl);
		dp = opendir(root->dinl);
		if (dp == NULL)
		{
			ft_printf("dir?: %s\n", root->dinl);
			perror("opendir");
			return (-1);
		}
		while ((entry = readdir(dp)))
		{
			ft_putstr(entry->d_name);
			if (entry->d_type == DT_DIR)
			{
				if (entry->d_name[0] != '.')
					root = ft_joinls(root, root->dinl, entry->d_name, boole);
				ft_putchar('/');
			}
			ft_putchar('\n');
		}
		closedir(dp);
		boole = 1;
		root = root->next;
	}
	return (0);
}
