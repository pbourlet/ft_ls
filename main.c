/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/23 01:09:13 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	char	*flag;
	t_nl	*l;
	int		boole;

	boole = 0;
	flag = NULL;
	if (ft_testflags(av[1]))
	{
		ft_testflags(av[1]) != 2 ? (flag = ft_strdup(av[1])) : 0;
		av++;
	}
	l = ft_isfile(flag, ft_sort(flag, ft_isdir(ft_sort(flag,
	ft_initls(flag, ac - 1, av + 1)))));
	while (l)
	{
		ft_recursif(flag, l, &boole);
		free(l->dinl);
		free(l);
		l = l->next;
	}
	return (1);
}
