/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:33:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/15 18:46:01 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printls(char *flag, t_nl *res, DIR *dp, int *boole)
{
	while (res)
	{
		if (ft_strcmp(res->dinl, ""))
		{
			ft_strchr(flag, 'l') ? ft_putstr("stat ") : 0;
			ft_putstr(res->dinl);
			res->dir == 1 ? ft_putendl("/") : ft_putchar('\n');
		}
		ft_strclr(res->dinl);
		free(res->dinl);
		free(res);
		res = res->next;
	}
	if (dp)
	{
		closedir(dp);
		*boole = 1;
	}
}
