/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soluce1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 06:00:18 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 09:23:11 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double		discriminant(t_lst *beg)
{
	double delta;

	delta = CARRE(beg->next->term.a)
			- (4 * beg->next->next->term.a * beg->term.a);
	return (delta);
}

void		soluce_complexe(t_lst *begin, double delta)
{
	dprintf(1, "Discriminant is strictly negative, \
the two complexes solutions are:\n");
	dprintf(1
		, "x1: (%g - i√%g) / %g = (%g - i%g) / %g"
		, begin->next->term.a == 0 ? 0 : -begin->next->term.a, -delta
		, (2 * begin->next->next->term.a)
		, begin->next->term.a == 0 ? 0 : -begin->next->term.a
		, raccarre(-delta), (2 * begin->next->next->term.a));
	simplify_complexe1(-begin->next->term.a
		, raccarre(-delta), (2 * begin->next->next->term.a));
	dprintf(1
		, "x2: (%g + i√%g) / %g = (%g + i%g) / %g"
		, begin->next->term.a == 0 ? 0 : -begin->next->term.a, -delta
		, (2 * begin->next->next->term.a)
		, begin->next->term.a == 0 ? 0 : -begin->next->term.a
		, raccarre(-delta), (2 * begin->next->next->term.a));
	simplify_complexe2(-begin->next->term.a
		, raccarre(-delta), (2 * begin->next->next->term.a));
}

void		one_soluce(t_lst *begin)
{
	if ((-begin->next->term.a / (2 * begin->next->next->term.a)) == 0)
		dprintf(1,
			"Disciminant is null, the only solution is :\n0\n");
	else
		dprintf(1,
			"Disciminant is null, the only solution is :\n%g\n",
			-begin->next->term.a / (2 * begin->next->next->term.a));
}

void		soluce_real(t_lst *begin, double delta)
{
	double	x1;
	double	x2;

	dprintf(1, "Discriminant is strictly positive, \
the two reals solutions are:\n");
	x1 = (-begin->next->term.a - raccarre(delta))
		/ (2 * begin->next->next->term.a);
	x2 = (-begin->next->term.a + raccarre(delta))
		/ (2 * begin->next->next->term.a);
	dprintf(1
		, "x1: (%g - √%g) / %g = %g\n"
		, -begin->next->term.a, delta
		, (2 * begin->next->next->term.a)
		, x1);
	dprintf(1
		, "x1: (%g + √%g) / %g = %g\n"
		, -begin->next->term.a, delta
		, (2 * begin->next->next->term.a)
		, x2);
}
