/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:40:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:59:48 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_nl	*ft_testarg(char *flag, int *boole, t_nl *list)
{
	t_nl	*res;
	int		taille[3];

	taille[0] = ft_lssize(list);
	res = ft_isfile(flag, list);
	taille[1] = ft_lssize(res);
	taille[1] != taille[0] ? *boole = 2 : 0;
	if (taille[1] != taille[0])
		res ? ft_putchar('\n') : 0;
	return (res);
}
