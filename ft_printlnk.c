/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlnk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 15:30:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/25 17:05:17 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printlnk(t_nl *res)
{
	char	buff[512];

	ft_memset(buff, 0, 512);
	readlink(res->dinl, buff, 512);
	ft_putstr(" -> ");
	ft_putstr(buff);
}
