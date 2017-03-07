/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:30:09 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 16:43:51 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls0(int flag, char *path)
{
	struct	winsize	w;
	struct	dirent	*entry;
	DIR				*dp;
	int				cpt;
	int				len;

	ioctl(0, TIOCGWINSZ, &w);
	cpt = w.ws_col;
	len = ft_flenmax(path, 0) + 1;
	dp = opendir(path);
	flag = flag + 1;
	while ((entry = readdir(dp)))
	{
		if (entry->d_name[0] != '.')
		{
			if (cpt - len < 0)
			{
				printf("\n");
				cpt = w.ws_col;
			}
			if (entry->d_type == DT_DIR)
				printf("\033[36;01m%-*s\033[0m", len, entry->d_name);
			else
				printf("%-*s", len, entry->d_name);
			cpt -= len;
		}
	}
	closedir(dp);
	return (1);
}
