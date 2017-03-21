/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:59:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/21 18:35:45 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl		*ft_nlcreate(char *flag, char *path, char *str)
{
	t_nl	*new;
	char	*complet;

	if (!(new = (t_nl*)ft_memalloc(sizeof(t_nl))))
		return (NULL);
	if (ft_strcmp(str, "") && (ft_strchr(flag, 'l') ||
	ft_strchr(flag, 't') || ft_strchr(flag, 'G')))
	{
		if (str[0] != '/')
		{
			complet = ft_strcjoin(path, '/');
			complet = ft_strjoinf(complet, str);
		}
		else
			complet = ft_strdup(str);
		ft_strchr(flag, 's') && !ft_strchr(flag, 't') && !ft_strchr(flag, 'l') ?
		stat(complet, &new->statis) : lstat(complet, &new->statis);
		free(complet);
	}
	if (!(new->dinl = ft_strdup(str)))
	{
		free(new);
		return (NULL);
	}
	new->dir = 0;
	new->next = NULL;
	return (new);
}
