/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/04 03:34:43 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls(int flag, char *path)
{
	struct	dirent *entry;
	DIR		*dp;
	int		len;

	len = ft_flenmax(path, (flag == 100 ? 1 : 0)) + 1;
	dp = opendir(path);
	if (dp == NULL)
	{
		perror("opendir");
		return (-1);
	}
	while((entry = readdir(dp)))
	{
		if (flag == 0)
			ft_ls0(flag, len, entry->d_name);
		else if (flag == 1)
			ft_ls1(flag, len, entry->d_name);
		else if (flag == 100)
			ft_la(flag, len, entry->d_name);
/*		if (entry->d_name[0] != '.')
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
*/	}
	(flag == 1 ? 0 : printf("\n"));
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
