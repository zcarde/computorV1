/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/23 17:07:17 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/24 09:22:47 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include <stdlib.h>
# include <stdio.h>
# include "libft.h"

# define ABS(x) (x > 0) ? x : -x
# define CARRE(x) x * x

typedef struct	s_term
{
	double	a;
	int		p;
}				t_term;

typedef struct	s_lst
{
	t_term			term;
	char			*cterm;
	struct s_lst	*next;
}				t_lst;

double			discriminant(t_lst *beg);
void			soluce_complexe(t_lst *begin, double delta);
void			soluce_real(t_lst *begin, double delta);
void			one_soluce(t_lst *begin);
void			insert_before(t_lst *temp, t_lst **beg, t_term term);

void			del_term(t_lst **begin, t_lst *del);
void			push_back_term_cpy(t_lst **begin, t_lst *cpy);
void			push_back_term(t_lst **begin, char *str);

t_lst			*make_list(char *eq);
t_lst			*make_list_2(char *eq);

double			raccarre(double nb);

void			print_error(char *str);
void			print_elem(t_lst *elem, int first);
void			print_lst(t_lst *beg);

void			reduce(t_lst **beg, t_lst **end);
void			reduce2(t_lst **beg);

void			soluce_second_deg(t_lst **begin);

int				soluce(t_lst **begin);

void			simplify_complexe1(double b, double delta, double a);
void			simplify_complexe2(double b, double delta, double a);

#endif
