/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:39:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/20 21:35:01 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_printall(char *flag, t_nl *res, t_nl *root)
{
	int len[FORMAT_SIZE];

	ft_strchr(flag, 'l') ? ft_sizemax(res, len) : 0;
		ft_printf("total %d\n", len[4]);
	while (res)
	{
		ft_printls(flag, res, root, len);
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
