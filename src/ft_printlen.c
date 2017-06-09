/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:40:23 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:57:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putlenstr(int len, char *content)
{
	int i;

	i = content ? ft_strlen(content) : 0;
	ft_putstr(content);
	while (i++ < len)
		ft_putchar(' ');
}

void	ft_putlennbr(int len, int content)
{
	int i;

	i = ft_nblen(content);
	while (i++ < len)
		ft_putchar(' ');
	ft_putnbr(content);
}
