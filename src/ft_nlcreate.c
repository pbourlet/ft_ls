/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:59:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:56:06 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_teststat(char *flag, char *str, char *complet, t_nl *new)
{
	if (ft_strcmp(str, ""))
	{
		if (ft_strchr(flag, '0') && stat(complet, &new->statis) < 0)
			return (0);
		if (lstat(complet, &new->statis) < 0)
			return (0);
	}
	return (1);
}

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
	if (!ft_teststat(flag, str, complet, new))
	{
		ft_putstr("ft_ls: ");
		perror((ft_strchr(complet, '/') ? ft_strrchr(complet, '/') + 1 :
					complet));
		free(complet);
		return (NULL);
	}
	if (!(new->dinl = complet))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
