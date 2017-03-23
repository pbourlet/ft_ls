/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:56:13 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/22 13:11:42 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_illegal(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_putendl("usage: ft_ls [-GRSadglrst] [file ...]");
	exit(1);
}

int		ft_testflags(char *s)
{
	int flag;
	int i;

	flag = -1;
	i = 1;
	if (!s || s[0] != '-')
		return (0);
	if (!ft_strcmp(s, "--"))
		return (2);
	if (s[0] == '-')
	{
		while (s[i])
		{
			if (s[i] == 'l' || s[i] == 'R' || s[i] == 'a' || s[i] == 'd' || s[i] == 'S'
				|| s[i] == 'r' || s[i] == 't' || s[i] == 'G' || s[i] == 'g' || s[i] == 's')
				flag = 1;
			else
				ft_illegal(s[i]);
			i++;
		}
	}
	return (flag);
}
