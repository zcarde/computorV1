/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 05:59:28 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 06:00:13 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	add(t_lst *sub, t_lst **beg)
{
	t_lst *temp;

	temp = *beg;
	while (temp)
	{
		if (temp->term.p == sub->term.p && temp != sub)
		{
			temp->term.a += sub->term.a;
			del_term(beg, sub);
			return ;
		}
		temp = temp->next;
	}
}

static void	substract(t_lst *sub, t_lst **beg)
{
	t_lst *temp;

	temp = *beg;
	while (temp)
	{
		if (temp->term.p == sub->term.p)
		{
			temp->term.a -= sub->term.a;
			return ;
		}
		temp = temp->next;
	}
	sub->term.a = -sub->term.a;
	push_back_term_cpy(beg, sub);
}

void		reduce(t_lst **beg, t_lst **end)
{
	t_lst *temp;

	temp = *end;
	while (temp)
	{
		substract(temp, beg);
		temp = temp->next;
	}
}

void		reduce2(t_lst **beg)
{
	t_lst *temp;

	temp = *beg;
	if (temp)
		temp = temp->next;
	else
		return ;
	while (temp)
	{
		add(temp, beg);
		temp = temp->next;
	}
}
