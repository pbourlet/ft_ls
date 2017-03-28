/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:59:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/28 15:17:52 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl		*ft_nlcreate(char *flag, char *path, char *str)
{
	t_nl	*new;
	char	*complet;

	if (!(new = (t_nl*)ft_memalloc(sizeof(t_nl))))
		return (NULL);
	if (!ft_strchr(flag, '0') && str[0] != '/')
		complet = ft_strjoin(path, str);
	else
		complet = ft_strdup(str);
	if (ft_strcmp(str, ""))
	{
		ft_strchr(flag, '0') ? stat(complet, &new->statis) :
		lstat(complet, &new->statis);
	}
	if (!(new->dinl = ft_strdup(complet)))
	{
		free(new);
		return (NULL);
	}
	free(complet);
	new->dir = 0;
	new->next = NULL;
	return (new);
}
