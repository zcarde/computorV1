/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:05:35 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 06:48:58 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		len_long(char *str)
{
	int i;

	i = 0;
	while (str[i] && ft_isdigit(str[i]))
		i++;
	return (i);
}

void	order(t_lst **beg)
{
	t_lst	*tmp;
	t_term	term;
	t_lst	*tmp2;

	tmp = *beg;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->term.p > tmp2->term.p)
			{
				term.p = tmp2->term.p;
				term.a = tmp2->term.a;
				tmp2->term.p = tmp->term.p;
				tmp2->term.a = tmp->term.a;
				tmp->term.p = term.p;
				tmp->term.a = term.a;
			}
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	make_all_exp(t_lst **beg)
{
	t_lst	*temp;
	int		i;
	t_term	term;

	i = 0;
	temp = *beg;
	while (temp)
	{
		if (temp->term.p < 0)
			print_error("Negative exposant");
		if (temp->term.p != i && i < 3)
		{
			term.a = 0.0;
			term.p = i;
			insert_before(temp, beg, term);
		}
		i++;
		temp = temp->next;
	}
}

int		main(int ac, char **av)
{
	t_lst	*begin;
	t_lst	*end;

	begin = NULL;
	if (ac != 2)
		print_error("Wrong number of arguments");
	begin = make_list(av[1]);
	end = make_list_2(ft_strchr(av[1], '=') + 1);
	reduce(&begin, &end);
	order(&begin);
	make_all_exp(&begin);
	reduce2(&begin);
	dprintf(1, "Reduced form : ");
	print_lst(begin);
	dprintf(1, " = 0\n");
	if (soluce(&begin) == -1)
		return (0);
}
