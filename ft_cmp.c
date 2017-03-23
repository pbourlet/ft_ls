/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 15:52:47 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/22 16:08:30 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int		ft_tests(t_nl *root, char *name)
{
	struct stat	st;

	stat(name, &st);
	ft_printf("root->dinl: %s // name:%s\n", root->dinl, name);
	return (1);
}

int		ft_cmp(t_nl *root, char *flag, char *name)
{
	if (ft_strchr(flag, 'S'))
	{
		ft_putchar('#');
		if (ft_tests(root, name))
			return (1);
		return (0);
	}
	else if (ft_strncmp(root->dinl, name, ft_strlen(root->dinl)))
		return (1);
	return (0);
}
