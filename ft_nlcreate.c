/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:59:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/15 19:05:21 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl		*ft_nlcreate(char *flag, char *path, char *str)
{
	t_nl	*new;
	char	*complet;

	if (!(new = (t_nl*)ft_memalloc(sizeof(t_nl))))
		return (NULL);
	if (ft_strcmp(str, "") && (ft_strchr(flag, 'l') || ft_strchr(flag, 't')))
	{
		complet = ft_strcjoin(path, '/');
		complet = ft_strjoinf(complet, str);
		if (lstat(complet, &new->statis) < 0)
		{
			ft_putstr("./ft_ls: ");
			perror(str);
		}
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
