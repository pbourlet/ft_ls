/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/03 13:24:42 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls(int flag, char *path)
{
	struct	dirent *entry;
	DIR		*dp;
	struct	stat statis;
	int		len;
	struct	winsize w;
	int		cpt;

	ioctl(0, TIOCGWINSZ, &w);
	cpt = w.ws_col;
//	len = ft_flenmax(path) + 1; windows = strlen + 2
	dp = opendir(path);
	if (dp == NULL)
	{
		perror("opendir");
		return (-1);
	}
	while((entry = readdir(dp)) && !flag)
	{
		if (entry->d_name[0] != '.')
		{
			len = ft_strlen(entry->d_name) + 2; // seulement pour windows
			if (cpt - len < 0 && !path)
			{
				ft_printf("\n");
				cpt = w.ws_col;
			}
			stat(entry->d_name, &statis);
//			ft_printf("// statsize: %i //", statis.st_size);
			if (S_ISREG(statis.st_mode) == 0)
				printf("\033[36;01m%-*s\033[0m", len, entry->d_name);
			else if (S_IEXEC & statis.st_mode)
				printf("\033[31m%-*s\033[0m", len, entry->d_name);
			else
				printf("%-*s", len, entry->d_name);
			cpt -= len;
		}
	}
	printf("\n");
	closedir(dp);
	return (0);
}

int		main(int av, char **ac)
{
	int	flag;

	flag = ft_testflags(ac[1]);
	ft_printf("flag: %d\n", flag);
	if (av == 1 && !flag && !ac[1])
		ft_ls(flag, ".");
	else if (av == 2 && flag && !ac[2])
		ft_ls(flag, ".");
	else if (av == 2 && !flag && ac[1])
		ft_ls(flag, ac[1]);
	if (av == 2 && flag && ac[2])
		ft_ls(flag, ac[1]);
	return(0);
}
