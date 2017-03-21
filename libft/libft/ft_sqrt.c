/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 14:52:15 by pbourlet          #+#    #+#             */
/*   Updated: 2016/11/16 14:53:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int r;
	int sqrt;

	r = 1;
	if (nb == 1)
		return (nb);
	while (r < nb)
	{
		sqrt = r * r;
		if (sqrt == nb)
			return (r);
		r++;
	}
	return (0);
}
