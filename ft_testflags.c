/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testflags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 12:56:13 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/03 19:16:39 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_testflags(char *s)
{
	int flag;

	flag = 0;
	if (!s)
		return (0);
	if (s[0] == '-')
	{
		if (ft_strstr(s, "1"))
			flag = flag + 1;
		if (ft_strstr(s, "R"))
			flag = flag + 10;
		if (ft_strstr(s, "a"))
			flag = 100;
		if (ft_strstr(s, "r"))
			flag = 1000;
		if (ft_strstr(s, "t"))
			flag = 10000;
	}
	return (flag);
}
