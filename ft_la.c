/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_la.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:30:18 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 16:36:59 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_la(int flag, DIR *dp, int len)
{
	struct	winsize	w;
	struct	dirent	*entry;
	int				cpt;

	ioctl(0, TIOCGWINSZ, &w);
	cpt = w.ws_col;
	flag = flag + 1;
	while ((entry = readdir(dp)))
	{
		if (cpt - len < 0)
		{
			ft_printf("\n");
			cpt = w.ws_col;
		}
		if (entry->d_type == DT_DIR /*-F*/)
			ft_printf("\033[36;01m%-*s\033[0m", len, entry->d_name);// ft_printf("/");
		else
			ft_printf("%-*s", len, entry->d_name);
		cpt -= len;
	}
	return (1);
}
