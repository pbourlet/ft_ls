/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:15:12 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/13 15:10:58 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_initls(int ac, char **av)
{
	t_nl	*root;
	t_nl	*conductor;

	if (!*av)
	{
		root = ft_nlcreate(".");
		return (root);
	}
	root = ft_nlcreate(*av++);
	ac--;
	conductor = root;
	while (ac-- && *av)
	{
		conductor->next = ft_nlcreate(*av++);
		conductor = conductor->next;
	}
	return (root);
}
