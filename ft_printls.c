/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 10:33:29 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/14 17:23:06 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_printls(t_nl *res, t_nl *root)
{
	while (res)
	{
		if (ft_strcmp(res->dinl, ""))
		{
			ft_putstr(res->dinl);
			res->dir == 1 ? ft_putendl("/") : ft_putchar('\n');
		}
		ft_strclr(res->dinl);
		free(res->dinl);
		free(res);
		res = res->next;
	}
	free(root->dinl);
	free(root);
	root = root->next;
	return (root);
}
