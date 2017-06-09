/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printtag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:04:32 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:58:11 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printtag(t_nl *root)
{
	if (S_ISDIR(root->statis.st_mode))
		ft_putchar('/');
	else if (S_ISLNK(root->statis.st_mode))
		ft_putchar('@');
	else if (S_ISFIFO(root->statis.st_mode))
		ft_putchar('|');
	else if (S_ISSOCK(root->statis.st_mode))
		ft_putchar('|');
	else if (S_ISWHT(root->statis.st_mode))
		ft_putchar('%');
	else if (S_IXOTH & root->statis.st_mode || S_IXGRP & root->statis.st_mode
			|| S_IXUSR & root->statis.st_mode)
		ft_putchar('*');
}
