/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 01:24:11 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 03:50:32 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

double	raccarre(double nb)
{
	double calc;
	double diff;

	if (nb == 0.0 || nb == 1.0)
		return (nb);
	diff = 0.0;
	calc = nb;
	while (calc != diff)
	{
		diff = calc;
		calc = 0.5 * (calc + nb / calc);
	}
	return (calc);
}
