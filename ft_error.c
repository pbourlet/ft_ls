/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:15:39 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/27 13:18:33 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_error(char *str)
{
	char	*tmp;

	tmp = ft_strjoin("ft_ls: ", str);
	perror((ft_strchr(str, '/') ? ft_strrchr(str, '/') + 1 : str));
	free(tmp);
}
