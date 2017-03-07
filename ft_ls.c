/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:28:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 21:40:21 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls(int flag, char *path)
{
	DIR		*dp;
	int		len;
	t_ls	*l;

	len = ft_flenmax(path, (flag == 100 ? 1 : 0)) + 1;
	dp = opendir(path);
	if (dp == NULL)
	{
		perror("opendir");
		return (-1);
	}
	if (flag == 0)
		ft_ls0(flag, path);
	else if (flag == 1)
		ft_ls1(flag, path);
	else if (flag == 10)
	{
		l = malloc(sizeof(char*) + sizeof(char*));
		l->path = path;
		ft_printf("%s\n", l->path);
//		ft_ls1(1, l->path);
		l = ft_lstck(flag, l);
		ft_printf("\n");
		ft_printf("%s\n", l->next->path);
		ft_lr(l);
		//	l = ft_lstck(flag, l);
	}
	else if (flag == 100)
		ft_la(flag, dp, len);
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
