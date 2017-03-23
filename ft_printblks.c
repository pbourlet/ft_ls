/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printblks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 13:04:18 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/22 13:20:49 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_ls.h"

void	ft_printblks(struct stat st, int *len)
{
	ft_putlennbr(len[5], st.st_blocks);
	ft_putchar(' ');
}
