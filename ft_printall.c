/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:39:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/24 20:04:47 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printall(char *flag, t_nl *res, char *path)
{
	t_nl	*tmp;
	int		len[FORMAT_SIZE];

	ft_strchr(flag, 's') || ft_strchr(flag, 'l') || ft_strchr(flag, 'g') ?
	ft_sizemax(flag, res, len) : 0;
	res && ft_strchr(flag, 'l') ? ft_printf("total %d\n", len[4]) : 0;
	while (res)
	{
		ft_printls(flag, res, path, len);
		ft_strclr(res->dinl);
		free(res->dinl);
		tmp = res->next;
		free(res);
		res = res->next;
	}
}
