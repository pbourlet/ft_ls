/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:50:19 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/25 21:31:06 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printtime(t_nl *ls)
{
	time_t curtime;
	struct timeval tv;

	gettimeofday(&tv, NULL); 
	curtime=tv.tv_sec;
	if (curtime - ls->statis.st_mtime > 15770000 ||
	curtime - ls->statis.st_mtime < -15770000)
	{
		ft_printf(" %.7s %.4s ", ctime(&ls->statis.st_mtime) + 4,
		ctime(&ls->statis.st_mtime) + 20);
	}
	else
		ft_printf(" %.12s ", ctime(&ls->statis.st_mtime) + 4);
}
