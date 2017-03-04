/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 18:41:07 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/03 20:45:00 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

int	ft_ls1(int flag, int len, char *flname)
{
	struct	stat	statis;

	if (flag == 1 && flname[0] != '.')
	{
		stat(flname, &statis);
		if (S_ISREG(statis.st_mode) == 0)
			printf("\033[36;01m%-*s\033[0m", len, flname);
		else if (S_IEXEC & statis.st_mode)
			printf("\033[31m%-*s\033[0m", len, flname);
		else
			printf("%-*s", len, flname);
		printf("\n");
	}
	return (1);
}
