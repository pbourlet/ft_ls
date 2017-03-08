/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/08 15:27:08 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	int 	flag;
	t_nl	*l;
	t_nl	*t;

	(void)ac;
	flag = ft_testflags(av[1]);
	ft_printf("---------main--------\nflag: %d\n", flag);
	l = ft_initls(av + 1);
	t = l;
	while (t)
	{
		ft_printf("arg: %s\n---------end---------\n", t->dinl);
		t = t->next;
	}
	ft_ls(flag, l);
	return(0);
}
