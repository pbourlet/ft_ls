/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/09 20:33:09 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	char 	*flag;
	t_nl	*l;
	t_nl	*t;
	t_nl	*str;

	(void)ac;
	str = NULL;
	flag = NULL;
	if (ft_testflags(av[1]) == 1)
	{
		flag = ft_strdup(av[1]);
		av++;
	}
	ft_printf("---------main--------\nflag: %s\n", flag);
	l = ft_initls(av + 1);
	t = l;
	while (t)
	{
		ft_printf("arg: %s\n", t->dinl);
		t = t->next;
	}
	ft_printf("----------end---------\n");
	str = ft_ls(str, flag, l);
	str = ft_sort(flag, str);
	ft_putendl("sortie:");
	while (str)
	{
		ft_putstr(str->dinl);
		str = str->next;
	}
	return(0);
}
