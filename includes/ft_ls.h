/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 21:20:43 by pbourlet         ###   ########.fr       */
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

typedef struct		l_list
{
	char			*path;
	int				dir;
	struct	l_list	*next;
}					t_ls;

int		ft_ls(int flag, char *path);
int		ft_flenmax(char *path, int la);
int		ft_testflags(char *s);
int		ft_ls1(int flag, char *path);
int		ft_la(int flag, DIR *dp, int len);
int		ft_ls0(int flag, char *path);
t_ls	*ft_lstck(int flag, t_ls *l);
int		ft_lr(t_ls *l);

#endif
