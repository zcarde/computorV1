/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 09:22:03 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 09:22:18 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void		simplify_complexe1(double b, double delta, double a)
{
	if (b / a == (int)(b / a) && delta / a == (int)(delta / a))
	{
		if (delta / a == 1)
			dprintf(1, " = \033[32m%g - i\033[0m", b / a);
		else
			dprintf(1, " = \033[32m%g - i%g\033[0m", b / a, delta / a);
	}
	dprintf(1, "\n");
}

void		simplify_complexe2(double b, double delta, double a)
{
	if (b / a == (int)(b / a) && delta / a == (int)(delta / a))
	{
		if (delta / a == 1)
			dprintf(1, " = \033[32m%g + i\033[0m", b / a);
		else
			dprintf(1, " = \033[32m%g + i%g\033[0m", b / a, delta / a);
	}
	dprintf(1, "\n");
}
