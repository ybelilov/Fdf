/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:10:01 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/05 19:10:03 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_tocenter(t_form *form)
{
	int		i;
	int		j;
	double	x;
	double	y;

	x = (form->crd[0][0]->x +
		form->crd[form->lenmapy - 1][form->lenmapx - 1]->x) / 2;
	y = (form->crd[0][0]->y +
		form->crd[form->lenmapy - 1][form->lenmapx - 1]->y) / 2;
	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx)
		{
			form->crd[i][j]->x += 500 - x;
			form->crd[i][j]->y += 500 - y;
			j++;
		}
		i++;
	}
}

void	ft_turn_x(t_form *form, int r)
{
	int		i;
	int		j;
	double	z;
	double	y;

	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx)
		{
			z = form->crd[i][j]->z;
			y = form->crd[i][j]->y;
			form->crd[i][j]->y = (y * cos(GR * RAD) + z * sin(GR * RAD) * r);
			form->crd[i][j]->z = (-y * sin(GR * RAD) * r + z * cos(GR * RAD));
			j++;
		}
		i++;
	}
	ft_print_form(form);
}

void	ft_turn_y(t_form *form, int r)
{
	int		i;
	int		j;
	double	x;
	double	z;

	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx)
		{
			x = form->crd[i][j]->x;
			z = form->crd[i][j]->z;
			form->crd[i][j]->x = (x * cos(GR * RAD) + z * sin(GR * RAD) * r);
			form->crd[i][j]->z = (-x * sin(GR * RAD) * r + z * cos(GR * RAD));
			j++;
		}
		i++;
	}
	ft_print_form(form);
}

void	ft_turn_z(t_form *form, int r)
{
	int		i;
	int		j;
	double	x;
	double	y;

	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx)
		{
			x = form->crd[i][j]->x;
			y = form->crd[i][j]->y;
			form->crd[i][j]->x = (x * cos(GR * RAD) - y * sin(GR * RAD) * r);
			form->crd[i][j]->y = (x * sin(GR * RAD) * r + y * cos(GR * RAD));
			j++;
		}
		i++;
	}
	ft_print_form(form);
}

void	ft_zoom(t_form *form, int r, int i, int j)
{
	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx)
		{
			if (r > 0)
			{
				form->crd[i][j]->x *= 0.9;
				form->crd[i][j]->y *= 0.9;
				form->crd[i][j]->z *= 0.9;
			}
			else
			{
				form->crd[i][j]->x *= 1.1;
				form->crd[i][j]->y *= 1.1;
				form->crd[i][j]->z *= 1.1;
			}
			j++;
		}
		i++;
	}
	ft_print_form(form);
}
