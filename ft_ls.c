/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/02 20:45:13 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls(char *path)
{
	struct	dirent *entry;
	DIR		*dp;
	struct	stat statis;
	int		len;
	struct	winsize w;
	int		cpt;

	ioctl(0, TIOCGWINSZ, &w);
	cpt = w.ws_col;
	len = ft_flenmax(path) + 1;
	dp = opendir(path);
	if (dp == NULL)
	{
		perror("opendir");
		return (-1);
	}
	while((entry = readdir(dp)))
	{
		if (entry->d_name[0] != '.')
		{
			if (cpt - len < 0)
			{
				ft_printf("\n");
				cpt = w.ws_col;
			}
			stat(entry->d_name, &statis);
//			ft_printf("// statsize: %i //", statis.st_size);
			if (S_ISREG(statis.st_mode) == 0)
				ft_printf("\033[36;01m%-*s\033[0m", len, entry->d_name);
			else if (S_IEXEC & statis.st_mode)
				ft_printf("\033[31m%-*s\033[0m", len, entry->d_name);
			else
				ft_printf("%-*s", len, entry->d_name);
			cpt -= len;
		}
	}

	closedir(dp);
	return (0);
}

int		main(int av, char **ac)
{
	if (av == 1 && !ac[1])
		ft_ls(".");
	if (av == 2)
		ft_ls(ac[1]);
	return(0);
}
