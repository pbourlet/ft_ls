/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:18:46 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/09 15:33:45 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_initls(char **av)
{
	t_nl	*root;
	t_nl	*conductor;

	if (!*av)
	{
		root = ft_nlcreate(".");
		return (root);
	}
	root = ft_nlcreate(*av++);
	conductor = root;
	while (*av)
		conductor->next = ft_nlcreate(*av++);
	return (root);
}
