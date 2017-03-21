/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:56:13 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/21 16:45:18 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_illegal(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_putendl("usage: ft_ls [-GRalrt] [file ...]");
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
	if (s[0] == '-')
	{
		while (s[i])
		{
			if (s[i] == 'l' || s[i] == 'R' || s[i] == 'a'
				|| s[i] == 'r' || s[i] == 't' || s[i] == 'G')
				flag = 1;
			else
				ft_illegal(s[i]);
			i++;
		}
	}
	return (flag);
}
