/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 11:53:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/30 12:57:34 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_begin(char *flag, t_nl *l, int *boole)
{
	while (l)
	{
		l->next || *boole == 2 ? ft_printf("%s:\n", l->dinl) : 0;
		ft_recursif(flag, l, boole);
		free(l->dinl);
		free(l);
		l = l->next;
	}
}

char	**ft_sorttab(char **tab)
{
	char	*tmp;
	int		i;

	i = 0;
	while (tab[i])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (tab);
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
	av = ft_sorttab(av);
	l = ft_testarg(flag, &boole, ft_sort(flag, ft_initls(flag, ac, av)));
	ft_begin(flag, l, &boole);
	free(flag);
	return (0);
}
