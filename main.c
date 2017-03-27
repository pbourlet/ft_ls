/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 13:18:41 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_begin(char *flag, t_nl *l, int *boole)
{
	while (l)
	{
		l->next ? ft_printf("%s:\n", l->dinl) : 0;
		ft_recursif(flag, l, boole);
		free(l->dinl);
		free(l);
		l = l->next;
	}
}

int		main(int ac, char **av)
{
	char	*flag;
	t_nl	*l;
	int		boole;

	boole = 0;
	av++;
	ac--;
	flag = ft_testflags(&av, &ac);
	if (!ft_strcmp(*av, "--"))
	{
		if (ac > 1)
			av++;
		else
		{
			ft_strclr(*av);
			*av = ".";
		}
	}
	l = ft_testarg(flag, ft_sort(flag, ft_initls(flag, ac, av)));
	ft_begin(flag, l, &boole);
	free(flag);
	return (0);
}
