/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 15:12:30 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 10:45:44 by pbourlet         ###   ########.fr       */
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
	while (complet[i])
	{
		if (complet[i] == '/')
			cpt1++;
		i++;
	}
	i = 0;
	while (dinl[i])
	{
		if (dinl[i] == '/')
			cpt2++;
		i++;
	}
	return (cpt1 - cpt2);
}

t_nl	*ft_joinls(char *flag, t_nl *root, char *path, char *ndir)
{
	t_nl	*conductor;
	t_nl	*tmp;
	char	*complet;

	complet = ft_strequ(path, "/") ? ft_strdup(path) : ft_strcjoin(path, '/');
	complet = ft_strjoinf(complet, ndir);
	tmp = root;
	while (tmp && ft_strncmp(tmp->dinl, complet, ft_strlen(tmp->dinl)))
		tmp = tmp->next;
	while (tmp && (ft_strnequ(tmp->dinl, complet, ft_strlen(tmp->dinl))
	|| !ft_level(tmp->dinl, complet)))
		tmp = tmp->next;
	conductor = root;
	while (conductor && conductor->next != tmp)
		conductor = conductor->next;
	tmp = conductor->next;
	conductor->next = ft_nlcreate(flag, ".", complet);
	conductor->next->next = tmp;
	ft_strclr(complet);
	free(complet);
	return (root);
}
