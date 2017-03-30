/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 16:05:56 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/30 13:00:25 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/ioctl.h>
# include <dirent.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include "../libft/includes/libft.h"

# define FORMAT_SIZE 6


typedef	struct		s_nl
{
	char			*dinl;
	int				dir;
	struct stat		statis;
	struct s_nl		*next;
}					t_nl;

void				ft_printall(char *flag, t_nl *res, char *path);
void				ft_printls(char *flag, t_nl *res, char *path, int *len);
void				ft_sizemax(char *flag, t_nl*ls, int *len);
void				ft_putlenstr(int len, char *content);
void				ft_putlennbr(int len, int content);
void				ft_printmode(struct stat st);
void				ft_printacl(char *name);
void				ft_printlnk(t_nl *res);
void				ft_printcolor(t_nl *root);
void				ft_printblks(struct stat st, int *len);
void				ft_printtime(t_nl *ls);
void				ft_recursif(char *flag, t_nl *root, int *boole);
void				ft_error(char *str);
void				ft_illegal(char c);

char				*ft_testflags(char ***s, int *ac);
char				*ft_strjoinf(char *dest, char *src);

int					ft_testdir(struct dirent *ent, char *path);
int					ft_lssize(t_nl *ls);

t_nl				*ft_initls(char *flag, int ac, char **av);
t_nl				*ft_joinls(char *flag, t_nl *root, char *path, char *av);
t_nl				*ft_nlcreate(char *flag, char *path, char *str);
t_nl				*ft_sort(char *flag, t_nl *str);
t_nl				*ft_testarg(char *flag, int *boole, t_nl *list);
t_nl				*ft_isfile(char *flag, t_nl *list);

#endif
