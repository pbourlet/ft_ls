/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:56:13 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:55:00 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_illegal(char c)
{
	ft_printf("ft_ls: illegal option -- %c\n", c);
	ft_putendl("usage: ft_ls [-FGRSadglrst] [file ...]");
	exit(1);
}

char	*ft_test(char *flag, char c)
{
	char	*tmp;

	!flag ? flag = ft_strnew(0) : 0;
	if (c == 'G' || c == 'R' || c == 'S' || c == 'a' || c == 'd' ||
	c == 'g' || c == 'l' || c == 'r' || c == 's' || c == 't' || c == 'F')
	{
		tmp = flag;
		flag = ft_strcjoin(tmp, c);
		free(tmp);
	}
	else
	{
		free(flag);
		ft_illegal(c);
	}
	return (flag);
}

char	*ft_conduite(char **s, int *i, char *flag)
{
	while (s[i[0]][0] == '-' && s[i[0]][1] != '-' && s[i[0]][i[1]])
		flag = ft_test(flag, s[i[0]][i[1]++]);
	if (s[i[0]][0] == '-' && s[i[0]][1] == '-')
		ft_illegal(s[i[0]][1]);
	return (flag);
}

char	*ft_testflags(char ***av, int *ac)
{
	char	*flag;
	char	**s;
	int		i[2];

	flag = NULL;
	s = *av;
	i[0] = 0;
	while (*ac && s[0][0] == '-')
	{
		if (!s[i[0]] || *s[i[0]] != '-' || !ft_strcmp(s[i[0]], "--")
		|| !ft_strcmp(s[i[0]], "-"))
		{
			flag && flag[0] ? *av = *av + i[0] : 0;
			return (flag);
		}
		i[1] = 1;
		flag = ft_conduite(s, i, flag);
		*ac -= 1;
		i[0]++;
	}
	if (!s[i[0]] || *s[i[0]] != '-' || !ft_strcmp(s[i[0]], "--")
	|| !ft_strcmp(s[i[0]], "-"))
		flag && flag[0] ? *av = *av + i[0] : 0;
	return (flag);
}
