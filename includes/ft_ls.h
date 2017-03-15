/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/15 18:59:30 by pbourlet         ###   ########.fr       */
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
	struct stat		statis;
	struct s_nl		*next;
}					t_nl;

int		ft_testflags(char *s);
int		ft_ls(t_nl *str, char *flag, t_nl *root);
int		ft_opentest(DIR **dp, t_nl *root);
t_nl	*ft_opentestls(DIR **dp, t_nl *root, int boole);
t_nl	*ft_initls(char *flag, int ac, char **av);
t_nl	*ft_joinls(char *flag, t_nl *root, char *path, char *av);
t_nl	*ft_nlcreate(char *flag, char *path, char *str);
char	*ft_strjoinf(char *dest, char *src);
t_nl	*ft_sort(char *flag, t_nl *str);
void	ft_printls(char *flag, t_nl *root, DIR *dp, int *boole);
t_nl	*ft_isdir(t_nl *list);

#endif
