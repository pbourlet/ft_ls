/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:27:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/09 17:49:00 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

char	*ft_strjoinf(char *dest, char *src)
{
	char *res;

	res = NULL;
	if ((!dest && src) || (!src && dest))
		return ((res = ft_strdup(!dest ? src : dest)));
	if (dest)
	{
		res = dest;
		dest = ft_strjoin(res, src);
		ft_strclr(res);
		free(res);
	}
	return (dest);
}
