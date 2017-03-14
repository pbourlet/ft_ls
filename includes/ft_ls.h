/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/14 17:34:02 by pbourlet         ###   ########.fr       */
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

typedef	struct		s_nl
{
	char			*dinl;
	int				dir;
	struct s_nl		*next;
}					t_nl;

int		ft_flenmax(char *path, int la);
int		ft_testflags(char *s);
int		ft_ls1(int flag, char *path);
int		ft_la(int flag, DIR *dp, int len);
int		ft_ls0(int flag, char *path);
int		ft_ls(t_nl *str, char *flag, t_nl *root);
int		ft_opentest(DIR **dp, t_nl *root);
t_nl	*ft_opentestls(DIR **dp, t_nl *root, int boole);
t_nl	*ft_initls(int ac, char **av);
t_nl	*ft_joinls(t_nl *root, char *path, char *av);
t_nl	*ft_nlcreate(char *str);
char	*ft_strjoinf(char *dest, char *src);
t_nl	*ft_sort(char *flag, t_nl *str);
t_nl	*ft_printls(t_nl *res, t_nl *root);

#endif
