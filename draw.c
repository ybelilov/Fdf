/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:09:20 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/05 19:09:22 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_print_form(t_form *form)
{
	if (form->img_ptr != NULL)
		mlx_destroy_image(form->mlx_ptr, form->img_ptr);
	form->img_ptr = mlx_new_image(form->mlx_ptr, 1000, 1000);
	form->adr = mlx_get_data_addr(form->img_ptr, &form->bits_per_pixel,
									&form->size_line, &form->endian);
	ft_tocenter(form);
	ft_img(form, 0, 0);
	mlx_put_image_to_window(form->mlx_ptr, form->window, form->img_ptr, 0, 0);
}

void	ft_img(t_form *form, int i, int j)
{
	i = 0;
	while (i < form->lenmapy)
	{
		j = 0;
		while (j < form->lenmapx - 1)
		{
			ft_draw_line(form->crd[i][j], form->crd[i][j + 1], form);
			if (i + 1 != form->lenmapy)
			{
				ft_draw_line(form->crd[i][j], form->crd[i + 1][j], form);
			}
			j++;
		}
		if (i + 1 != form->lenmapy)
		{
			ft_draw_line(form->crd[i][j], form->crd[i + 1][j], form);
		}
		i++;
	}
}

void	ft_draw(t_crd *crd1, t_crd *crd2, t_form *form)
{
	S.x1 = crd1->x;
	S.y1 = crd1->y;
	S.x2 = crd2->x;
	S.y2 = crd2->y;
	S.dx = abs((int)crd2->x - (int)crd1->x);
	S.dy = abs((int)crd2->y - (int)crd1->y);
	S.sx = crd1->x < crd2->x ? 1 : -1;
	S.sy = crd1->y < crd2->y ? 1 : -1;
	S.er = S.dx - S.dy;
}

void	ft_draw_line(t_crd *crd1, t_crd *crd2, t_form *form)
{
	ft_draw(crd1, crd2, form);
	if (S.x2 <= 999 && S.x2 >= 0 && S.y2 >= 0
			&& S.y2 <= 999)
		form->adr[(S.x2 + (S.y2 * form->size_line / 4))
					* 4 + form->col] = 255;
	while (S.x1 != S.x2 || S.y1 != S.y2)
	{
		if (S.x1 <= 999 && S.x1 >= 0 && S.y1 >= 0
				&& S.y1 <= 999)
			form->adr[(S.x1 + (S.y1 * form->size_line / 4))
						* 4 + form->col] = 255;
		S.er2 = S.er * 2;
		if (S.er2 > -S.dy)
		{
			S.er -= S.dy;
			S.x1 += S.sx;
		}
		if (S.er2 < S.dx)
		{
			S.er += S.dx;
			S.y1 += S.sy;
		}
	}
}
