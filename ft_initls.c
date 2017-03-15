/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:15:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/15 19:04:27 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_initls(char *flag, int ac, char **av)
{
	t_nl		*root;
	t_nl		*conductor;

	if (!*av)
		return ((root = ft_nlcreate(flag, ".", ".")));
	root = ft_nlcreate(flag, ".", *av++);
	ac--;
	conductor = root;
	while (ac-- && *av)
	{
		conductor->next = ft_nlcreate(flag, ".", *av++);
		conductor = conductor->next;
	}
	return (root);
}
