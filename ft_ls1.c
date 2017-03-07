/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:41:07 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 17:26:32 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_ls1(int flag, char *path)
{
	struct	dirent	*entry;
	DIR				*dp;

	flag = flag + 1;
	dp = opendir(path);
	while ((entry = readdir(dp)))
	{
		if (entry->d_name[0] != '.')
		{
			if (entry->d_type == DT_DIR)
				printf("\033[36;01m%-s\033[0m", entry->d_name);
			else
				printf("%-s", entry->d_name);
			printf("\n");
		}
	}
	closedir(dp);
	return (1);
}
