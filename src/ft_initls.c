/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:46:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:55:21 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nl	*ft_initls(char *flag, int ac, char **av)
{
	t_nl		*root;
	t_nl		*conductor;
	char		*tmp;

	tmp = !flag ? ft_strdup("0") : ft_strcjoin(flag, '0');
	root = NULL;
	if (*av == NULL)
		root = ft_nlcreate(tmp, NULL, ".");
	while (ac && *av && root == NULL)
	{
		root = ft_nlcreate(tmp, NULL, *av++);
		ac--;
	}
	conductor = root;
	while (ac-- && *av)
	{
		conductor->next = ft_nlcreate(tmp, NULL, *av++);
		conductor->next ? conductor = conductor->next : 0;
	}
	free(tmp);
	return (root);
}
