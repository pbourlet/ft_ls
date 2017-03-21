/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 11:39:22 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/21 19:16:11 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_printall(char *flag, t_nl *res, t_nl *root)
{
	t_nl	*tmp;
	int		len[FORMAT_SIZE];

	ft_strchr(flag, 'l') || ft_strchr(flag, 'g') ? ft_sizemax(flag, res, len) : 0;
	res->next && root->next ? ft_printf("total %d\n", len[4]) : 0;
	while (res)
	{
		ft_printls(flag, res, root, len);
		ft_strclr(res->dinl);
		free(res->dinl);
		tmp = res->next;
		free(res);
		res = res->next;
	}
	free(root->dinl);
	free(root);
	root = root->next;
	return (root);
}
