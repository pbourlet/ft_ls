/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/03 19:35:46 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/ioctl.h>

# include <dirent.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include "../libft/includes/libft.h"

int		ft_ls(int flag, char *path);
int		ft_flenmax(char *path, int la);
int		ft_testflags(char *s);
int		ft_ls1(int flag, int len, char *flname);
int		ft_la(int flag, int len, char *flname);
int		ft_ls0(int flag, int len, char *flname);

#endif
