/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:33:07 by pbourlet          #+#    #+#             */
/*   Updated: 2017/06/09 17:57:11 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_printcolor(t_nl *root)
{
	if ((S_ISVTX & root->statis.st_mode) && (S_IXOTH & root->statis.st_mode) &&
	S_IWOTH & root->statis.st_mode)
		ft_putstr("\033[42m\033[30m");
	else if (S_ISDIR(root->statis.st_mode) && S_IRUSR & root->statis.st_mode &&
	S_IWUSR & root->statis.st_mode && S_IXUSR & root->statis.st_mode &&
	S_IRGRP & root->statis.st_mode && S_IWGRP & root->statis.st_mode &&
	S_IXGRP & root->statis.st_mode && S_IROTH & root->statis.st_mode &&
	S_IWOTH & root->statis.st_mode && S_IXOTH & root->statis.st_mode)
		ft_putstr("\033[43m\033[30m");
	else if (S_ISDIR(root->statis.st_mode))
		ft_putstr("\033[36;01m");
	else if (S_ISBLK(root->statis.st_mode))
		ft_putstr("\033[46m\033[34m");
	else if (S_ISCHR(root->statis.st_mode))
		ft_putstr("\033[43m\033[34m");
	else if (S_ISLNK(root->statis.st_mode))
		ft_putstr("\033[35m");
	else if (S_ISFIFO(root->statis.st_mode))
		ft_putstr("\033[33m");
	else if (S_ISSOCK(root->statis.st_mode))
		ft_putstr("\033[36m");
	else if (S_IXOTH & root->statis.st_mode || S_IXGRP & root->statis.st_mode
	|| S_IXUSR & root->statis.st_mode)
		ft_putstr("\033[31m");
}
