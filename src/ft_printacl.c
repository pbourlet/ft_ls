/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:02:24 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:56:16 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printacl(char *name)
{
	acl_t acl;

	acl = acl_get_file(name, ACL_TYPE_EXTENDED);
	if (listxattr(name, NULL, 0, XATTR_NOFOLLOW) > 0)
		ft_putchar('@');
	else if (acl)
		ft_putchar('+');
	else
		ft_putchar(' ');
	acl_free((void*)acl);
}
