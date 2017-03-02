/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flenmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 18:47:26 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/02 18:48:12 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_flenmax(char *path)
{
	struct	dirent *entry;
	DIR		*dp;
	int		len;
	int		lentmp;

	len = 0;
	dp = opendir(path);
	if (dp == NULL)
	{
		perror("opendir");
		return (-1);
	}
	while ((entry = readdir(dp)))
	{
		if (entry->d_name[0] != '.')
		{
			lentmp = ft_strlen(entry->d_name);
			(lentmp > len ? len = lentmp : 0);
		}
	}
	closedir(dp);
	return (len);
}
