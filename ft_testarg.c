/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:40:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 13:27:08 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_testarg(char *flag, int *boole, t_nl *list)
{
	t_nl	*res;
	int		taille[3];

	taille[0] = ft_lssize(list);
	res = ft_sort(flag, ft_isdir(list));
	taille[1] = ft_lssize(res);
	res = ft_isfile(flag, res);
	taille[2] = ft_lssize(res);
	taille[1] != taille[0] || taille[2] != taille[0] ? *boole = 2 : 0;
	if (taille[2] != taille[1])
		res ? ft_putchar('\n') : 0;
	return (res);
}
