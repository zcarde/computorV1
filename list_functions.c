/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:15:43 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 06:48:46 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

static t_term	get_term(char *str)
{
	t_term	term;
	int		i;

	i = -1;
	term.a = ft_datoi(str + i + 1);
	while (str[++i] && str[i] != 'X')
		if (ft_isdigit(str[i]))
			break ;
	if (str[i] == 'X')
		term.a = (*str == '-') ? -1 : 1;
	i = 0;
	while (str[i] && str[i] != 'X')
		i++;
	if (str[i] == 'X' && str[i + 1] != '^')
		term.p = 1;
	else if (str[i] == 'X')
		term.p = ft_datoi(str + i + 2);
	if (str[i] == '\0')
	{
		term.a = ft_datoi(str);
		term.p = 0;
	}
	return (term);
}

void			del_term(t_lst **begin, t_lst *del)
{
	t_lst *temp;

	if (*begin == del)
	{
		*begin = del->next;
		free(del);
		return ;
	}
	temp = *begin;
	while (temp->next)
	{
		if (temp->next == del)
		{
			temp->next = del->next;
			free(del);
			return ;
		}
		temp = temp->next;
	}
}

void			push_back_term_cpy(t_lst **begin, t_lst *cpy)
{
	t_lst	*new_elem;
	t_lst	*temp;

	new_elem = (t_lst *)malloc(sizeof(t_lst));
	new_elem->cterm = ft_strdup(cpy->cterm);
	new_elem->term.a = cpy->term.a;
	new_elem->term.p = cpy->term.p;
	new_elem->next = NULL;
	if (!*begin)
		*begin = new_elem;
	else
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		temp->next = new_elem;
	}
}

void			push_back_term(t_lst **begin, char *str)
{
	t_lst	*new_elem;
	t_lst	*temp;

	new_elem = (t_lst *)malloc(sizeof(t_lst));
	new_elem->cterm = str;
	new_elem->term = get_term(str);
	new_elem->next = NULL;
	if (!*begin)
		*begin = new_elem;
	else
	{
		temp = *begin;
		while (temp->next)
			temp = temp->next;
		temp->next = new_elem;
	}
}
