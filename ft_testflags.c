/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:56:13 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/24 22:37:10 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_illegal(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_putendl("usage: ft_ls [-GRSadglrst] [file ...]");
	exit(1);
}

char	*ft_test(char *flag, char c)
{
	!flag ? flag = ft_strnew(0) : 0;
	if (c == 'G' || c == 'R' || c == 'S' || c == 'a' || c == 'd' ||
	c == 'g' || c == 'l' || c == 'r' || c == 's' || c == 't')
		flag = ft_strcjoin(flag, c);
	else
		ft_illegal(c);
	return (flag);
}

char	*ft_testflags(char ***av, int *ac)
{
	char	*flag;
	char	**s;
	int 	i[2];

	flag = NULL;
	s = *av;
	i[0] = 0;
	while (*ac && s[0][0] == '-')
	{
		i[1] = 1;
		while (s[i[0]][0] == '-' && s[i[0]][1] != '-' && s[i[0]][i[1]])
			flag = ft_test(flag, s[i[0]][i[1]++]);
		if (!s[i[0]] || *s[i[0]] != '-' || !ft_strcmp(s[i[0]], "--"))
		{
			flag[0] ? *av = *av + i[0] : 0;
			return (flag);
		}
		*ac -= 1;
		i[0]++;
	}
	if (!s[i[0]] || *s[i[0]] != '-' || !ft_strcmp(s[i[0]], "--"))
	{
		flag && flag[0] ? *av = *av + i[0] : 0;
		return (flag);
	}
	return (flag);
}
