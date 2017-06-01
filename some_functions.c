/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:51:29 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/10 14:51:31 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_toisometric(t_form *form)
{
	int i;
	int j;

	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx)
		{
			form->crd[i][j]->y = (form->crd[i][j]->x
				+ 2 * form->crd[i][j]->y + form->crd[i][j]->z) / sqrt(6);
			form->crd[i][j]->x = (form->crd[i][j]->x
				- form->crd[i][j]->z) * sqrt(3) / sqrt(6);
			j++;
		}
		i++;
	}
	ft_print_form(form);
}

int		ft_strlenarray(char **ar)
{
	int len;

	len = 0;
	while (*ar)
	{
		if (ft_check(*ar) == 1)
			ft_error(3);
		ar++;
		len++;
	}
	return (len);
}

void	ft_error(int i)
{
	i == 1 ? printf("Different lengths of lines !") : 0;
	i == 2 ? printf("Bad file !") : 0;
	i == 3 ? printf("Invalid content") : 0;
	exit(0);
}

int		ft_check(char *s)
{
	if (*s == '-')
		s++;
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s != ',' && *s != '\0')
		ft_error(3);
	if (*s == '\0')
		return (0);
	s++;
	*s != '0' ? ft_error(3) : s++;
	*s != 'x' ? ft_error(3) : s++;
	ft_strlen(s) != 6 ? ft_error(3) : 0;
	while (*s)
		ft_strchr("0123456789abcdefABCDEF", *s) == NULL ?
			ft_error(3) : s++;
	return (0);
}

void	ft_color(t_form *form)
{
	form->col == 2 ? form->col -= 2 : form->col++;
	ft_print_form(form);
}
