/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:12:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/08 19:29:02 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_level(char *dinl, char *complet)
{
	int i;
	int cpt1;
	int cpt2;

	i = 0;
	cpt1 = 0;
	cpt2 = 0;
	while (complet[i] && dinl[i])
	{
		if (complet[i] == '/')
			cpt1++;
		if (dinl[i] == '/')
			cpt2++;
		i++;
	}
	return (cpt1 - cpt2);
}

t_nl	*ft_joinls(t_nl *root, char *path, char *ndir, int first)
{
	t_nl	*conductor;
	t_nl	*tmp;
	char	*complet;

	complet = ft_strjoin(path, "/");
	complet = ft_strjoin(complet, ndir);
	conductor = root;
	while (conductor->next && (!first || !(ft_level(conductor->dinl, complet) &&
		(ft_strnequ(conductor->dinl, complet, ft_strlen(conductor->dinl))))))
		conductor = conductor->next;
	tmp = conductor->next;
	conductor->next = ft_nlcreate(complet);
	conductor->next->next = tmp;
	return (root);
}
