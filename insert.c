/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/24 06:02:01 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 06:02:14 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	insert_before(t_lst *temp, t_lst **beg, t_term term)
{
	t_lst	*new_elem;
	t_lst	*tmp;

	new_elem = (t_lst *)malloc(sizeof(t_lst));
	new_elem->term = term;
	tmp = *beg;
	while (tmp->next)
	{
		if (tmp->next == temp)
		{
			new_elem->next = temp;
			tmp->next = new_elem;
			return ;
		}
		tmp = tmp->next;
	}
}
