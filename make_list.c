/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 05:58:16 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 06:32:13 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

t_lst	*make_list(char *eq)
{
	t_lst	*beg;
	int		i;
	int		j;

	beg = NULL;
	i = 0;
	j = 0;
	while (eq[i])
	{
		if (eq[i] == '=')
			break ;
		if ((eq[i] == '+' || eq[i] == '-') && i != 0 && eq[i - 1] != '^')
		{
			push_back_term(&beg, ft_strsub(eq, j, i - j));
			j = i;
		}
		i++;
	}
	push_back_term(&beg, ft_strsub(eq, j, i - j));
	return (beg);
}

t_lst	*make_list_2(char *eq)
{
	t_lst	*beg;
	int		i;
	int		j;

	beg = NULL;
	i = 0;
	j = 0;
	while (eq[i])
	{
		if (eq[i] == '+' || eq[i] == '-')
		{
			push_back_term(&beg, ft_strsub(eq, j, i - j));
			j = i;
		}
		i++;
	}
	push_back_term(&beg, ft_strsub(eq, j, i - j));
	return (beg);
}
