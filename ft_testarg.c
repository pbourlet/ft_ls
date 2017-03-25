/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:40:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/25 15:20:58 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_testarg(char *flag, t_nl *list)
{
	t_nl	*res;
	int	taille[3];

	taille[0] = ft_lssize(list);
	res = ft_sort(flag, ft_isdir(list));
	taille[1] = ft_lssize(res);
	res = ft_isfile(flag, res);
	taille[2] = ft_lssize(res);
	if (taille[1] != taille [0] || taille[2] != taille[0])
	{
		res ? ft_putchar('\n') : 0;
	}
	return (res);
}
