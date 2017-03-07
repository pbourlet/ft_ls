/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbourlet <pbourlet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:35:35 by pbourlet          #+#    #+#             */
/*   Updated: 2017/03/07 19:46:24 by pbourlet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a.h"
#include <stdio.h>
#include <stdlib.h>

void	disp(t_la *begin)
{
	while (begin)
	{
		printf("%s\n", begin->str);
		begin = begin->next;
	}
}

t_la	*ft_tab(char **tab)
{
	t_la	*b;
	t_la	*l;
	int		i;

	i = 0;
	b = malloc(sizeof(char *) * 2);
	b->str = tab[i++];
	b->next = NULL;
	while (tab[i])
	{
		if (b->next == NULL)
		{
			b->next = malloc(sizeof(char *) * 2);
			l = b->next;
			l->str = tab[i];
		}
		else
		{
			l->next = malloc(sizeof(char *) * 2);
			l = l->next;
			l->str = tab[i];
			l->next = NULL;
		}
		i++;
	}
	return (b);
}

int		main(void)
{
	t_la	*begin;
	char *tab[10] = {"hello", "bjt", "ass", "peremptoire", "nik"};

	begin = ft_tab(tab);
	disp(begin);
	return (0);
}
