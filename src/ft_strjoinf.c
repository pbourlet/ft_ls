/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:27:28 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:59:39 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_strjoinf(char *dest, char *src)
{
	char *tmp;

	tmp = NULL;
	if ((!dest && src) || (!src && dest))
		return ((tmp = ft_strdup(!dest ? src : dest)));
	if (dest)
	{
		tmp = dest;
		dest = ft_strjoin(tmp, src);
		ft_strclr(tmp);
		free(tmp);
	}
	return (dest);
}
