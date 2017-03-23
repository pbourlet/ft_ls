/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:02:24 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/23 00:57:56 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printacl(char *name, char *path)
{
	acl_t   acl;
	char	*tmp;

	tmp = ft_strcjoin(path, '/');
	tmp = ft_strjoinf(tmp, name);
	acl = acl_get_file(tmp, ACL_TYPE_EXTENDED);
	if (listxattr(tmp, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if (acl)
		ft_putchar('+');
	else
		ft_putchar(' ');
	acl_free((void*)acl);
	free(tmp);
}
