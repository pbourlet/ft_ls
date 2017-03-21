/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlnk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:30:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/21 15:51:43 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printlnk(t_nl *res, t_nl *root)
{
	char	*complet;
	char	buff[512];

	complet = ft_strcjoin(root->dinl, '/');
	complet = ft_strjoinf(complet, res->dinl);
	ft_memset(buff, 0, 512);
	readlink(complet, buff, 512);
	ft_putstr(" -> ");
	ft_putstr(buff);
	free(complet);
}
