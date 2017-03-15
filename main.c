/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/15 18:38:11 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	char	*flag;
	t_nl	*l;
	t_nl	*t;
	t_nl	*str;

	str = NULL;
	flag = NULL;
	if (ft_testflags(av[1]) == 1)
	{
		flag = ft_strdup(av[1]);
		av++;
	}
	ft_printf("---------main--------\nflag: %s\n", flag);
	l = ft_sort(flag, ft_isdir(ft_initls(flag, ac - 1, av + 1)));
	t = l;
	while (t)
	{
		ft_printf("arg: %s\n", t->dinl);
		ft_printf("stat: %c\n", S_ISREG(t->statis.st_mode) == 0 ? 'd' : '-');
		t = t->next;
	}
	ft_printf("----------end---------\n");
	ft_ls(str, flag, l);
	return (0);
}
