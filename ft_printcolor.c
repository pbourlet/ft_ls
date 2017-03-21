/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:33:07 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/21 18:42:54 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printcolor(t_nl *root)
{
	if (S_ISDIR(root->statis.st_mode))
		ft_putstr("\033[36;01m");
	else if (S_ISLNK(root->statis.st_mode))
		ft_putstr("\033[35m");
	else if (S_ISFIFO(root->statis.st_mode))
		ft_putstr("\033[33m");
	else if (S_IXOTH & root->statis.st_mode || S_IXGRP & root->statis.st_mode
	|| S_IXUSR & root->statis.st_mode)
		ft_putstr("\033[31m");
}
