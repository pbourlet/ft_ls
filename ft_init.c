/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 13:18:46 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/08 17:11:29 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_initls(char **av)
{
	t_nl	*root;
	t_nl	*conductor;

	if (ft_testflags(av[0]))
		av++;
	root = ft_nlcreate(*av++);
	conductor = root;
	while (*av)
		conductor->next = ft_nlcreate(*av++);
	return (root);
}
