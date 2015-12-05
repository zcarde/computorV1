/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 05:58:44 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 06:58:48 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	print_error(char *str)
{
	ft_putstr("\033[31m");
	ft_putstr(str);
	ft_putendl("\033[0m");
	exit(-1);
}

void	print_elem(t_lst *elem, int first)
{
	if (first && elem->term.a >= 0)
		dprintf(1, " + ");
	else if (elem->term.a < 0)
	{
		if (!first)
			dprintf(1, "- ");
		else
			dprintf(1, " - ");
	}
	if (elem->term.a != 1 || elem->term.p == 0)
		dprintf(1, "%g", ABS(elem->term.a));
	if (elem->term.a != 1)
	{
		if (elem->term.p == 1)
			dprintf(1, " * X");
		else if (elem->term.p != 0)
			dprintf(1, " * X^%d", elem->term.p);
	}
	else
	{
		if (elem->term.p == 1 && elem->term.a != 1)
			dprintf(1, "%g * X", ABS(elem->term.a));
		else if (elem->term.p != 0)
			dprintf(1, "%g * X^%d", ABS(elem->term.a), elem->term.p);
	}
}

void	print_lst(t_lst *beg)
{
	t_lst	*temp;
	int		first;

	first = 0;
	temp = beg;
	while (temp)
	{
		if (temp->term.a != 0)
		{
			print_elem(temp, first);
			first++;
		}
		temp = temp->next;
	}
	if (first == 0)
		dprintf(1, "0");
}
