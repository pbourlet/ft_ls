/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 19:45:08 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/09 20:45:04 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

t_nl	*ft_sort(char *flag, t_nl *str)
{
	t_nl *conduct;
	char *tmp;

	conduct = str;
	(void)flag;
	while (conduct)
	{
		ft_printf("conduct->dinl: %s\n", conduct->dinl);
		if (conduct->next && ft_strcmp(conduct->dinl, conduct->next->dinl) >  0)
		{
			tmp = conduct->dinl;
			conduct->dinl = conduct->next->dinl;
			conduct->next->dinl = tmp;
		}
		conduct = conduct->next;
	}
	return (str);
}
