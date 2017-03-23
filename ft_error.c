/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:15:39 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/22 22:20:37 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_error(char *str)
{
	ft_putstr("ft_ls: ");
	perror((ft_strchr(str, '/') ? ft_strrchr(str, '/') + 1 : str));
}
