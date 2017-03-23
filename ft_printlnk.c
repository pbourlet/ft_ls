/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlnk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:30:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/23 00:10:49 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printlnk(t_nl *res, char *path)
{
	char	*complet;
	char	buff[512];

	complet = ft_strcjoin(path, '/');
	complet = ft_strjoinf(complet, res->dinl);
	ft_memset(buff, 0, 512);
	readlink(complet, buff, 512);
	ft_putstr(" -> ");
	ft_putstr(buff);
	free(complet);
}
