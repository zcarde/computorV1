/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soluce2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 06:02:30 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 09:24:18 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static void	soluce_first_deg(t_lst **begin)
{
	if ((*begin)->term.a == 0)
		dprintf(1,
			"The solution is:\n0\n");
	else
		dprintf(1,
			"The solution is:\n%g\n"
			, -(*begin)->term.a / (*begin)->next->term.a);
}

static void	soluce_no_deg(t_lst **begin)
{
	if ((*begin)->term.a != 0)
		dprintf(1, "This polynome haven't solution\n");
	else
		dprintf(1, "All reals are solution\n");
}

static int	degree(t_lst **beg)
{
	int		deg;
	t_lst	*temp;

	temp = *beg;
	deg = 0;
	while (temp)
	{
		if (temp->term.p > deg && temp->term.a != 0)
			deg = temp->term.p;
		temp = temp->next;
	}
	dprintf(1, "Polynomial degree: %d\n", deg);
	if (deg > 2)
		dprintf(1, "\033[31mDegree is higher than 2\033[0m\n");
	return (deg);
}

void		soluce_second_deg(t_lst **begin)
{
	double	delta;

	delta = discriminant(*begin);
	if (delta < 0)
		soluce_complexe(*begin, delta);
	else if (delta == 0)
		one_soluce(*begin);
	else
		soluce_real(*begin, delta);
}

int			soluce(t_lst **begin)
{
	int deg;

	deg = degree(begin);
	if (deg > 2)
		return (-1);
	if (deg == 2)
		soluce_second_deg(begin);
	else if (deg == 1)
		soluce_first_deg(begin);
	else
		soluce_no_deg(begin);
	return (0);
}
