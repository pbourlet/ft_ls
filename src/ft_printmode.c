/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 17:10:54 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:58:03 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printusr(struct stat st)
{
	ft_putchar(S_IRUSR & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWUSR & st.st_mode ? 'w' : '-');
	if (S_ISUID & st.st_mode && !(S_IXUSR & st.st_mode))
		ft_putchar('S');
	else if (S_ISUID & st.st_mode && (S_IXUSR & st.st_mode))
		ft_putchar('s');
	else
		ft_putchar(S_IXUSR & st.st_mode ? 'x' : '-');
}

void	ft_printgrp(struct stat st)
{
	ft_putchar(S_IRGRP & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWGRP & st.st_mode ? 'w' : '-');
	if (S_ISGID & st.st_mode && !(S_IXGRP & st.st_mode))
		ft_putchar('S');
	else if (S_ISGID & st.st_mode && (S_IXGRP & st.st_mode))
		ft_putchar('s');
	else
		ft_putchar(S_IXGRP & st.st_mode ? 'x' : '-');
}

void	ft_printoth(struct stat st)
{
	ft_putchar(S_IROTH & st.st_mode ? 'r' : '-');
	ft_putchar(S_IWOTH & st.st_mode ? 'w' : '-');
	if ((S_ISVTX & st.st_mode) && (S_IXOTH & st.st_mode))
		ft_putchar('t');
	else if ((S_ISVTX & st.st_mode) && !(S_IXOTH & st.st_mode))
		ft_putchar('T');
	else
		ft_putchar(S_IXOTH & st.st_mode ? 'x' : '-');
}

void	ft_printmode(struct stat st)
{
	S_ISBLK(st.st_mode) ? ft_putchar('b') : 0;
	S_ISCHR(st.st_mode) ? ft_putchar('c') : 0;
	S_ISFIFO(st.st_mode) ? ft_putchar('p') : 0;
	S_ISREG(st.st_mode) ? ft_putchar('-') : 0;
	S_ISDIR(st.st_mode) ? ft_putchar('d') : 0;
	S_ISLNK(st.st_mode) ? ft_putchar('l') : 0;
	S_ISSOCK(st.st_mode) ? ft_putchar('s') : 0;
	ft_printusr(st);
	ft_printgrp(st);
	ft_printoth(st);
}
