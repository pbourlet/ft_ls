/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/20 21:35:00 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		main(int ac, char **av)
{
	char	*flag;
	t_nl	*l;
	t_nl	*str;

	str = NULL;
	flag = NULL;
	if (ft_testflags(av[1]) == 1)
	{
		flag = ft_strdup(av[1]);
		av++;
	}
	l = ft_isfile(flag, ft_sort(flag, ft_isdir(ft_sort(flag,
	ft_initls(flag, ac - 1, av + 1)))));
	ft_ls(str, flag, l);
	return (0);
}