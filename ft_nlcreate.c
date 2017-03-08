/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nlcreate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:59:31 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/08 17:11:06 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_nlcreate(char *str)
{
	t_nl *new;

	if (!(new = (t_nl*)ft_memalloc(sizeof(t_nl))))
		return (NULL);
	if (!(new->dinl = ft_strdup(str)))
	{
		free(new);
		return (NULL);
	}
	new->next = NULL;
	return (new);
}
