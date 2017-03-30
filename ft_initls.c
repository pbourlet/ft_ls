/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initls.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 10:46:20 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/30 12:57:38 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

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
