/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 14:40:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/30 12:57:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

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
