/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:09:31 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/05 19:09:33 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>
# define RAD (3.14 / 180)
# define GR 2
# define S form->s

typedef	struct		s_draw
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				er;
	int				er2;
}					t_draw;

typedef struct		s_crd
{
	double			x;
	double			y;
	double			z;
}					t_crd;

typedef struct		s_form
{
	int				lenmapx;
	int				lenmapy;
	int				col;
	t_crd			***crd;
	t_draw			s;
	void			*mlx_ptr;
	void			*window;
	void			*img_ptr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	char			*adr;
}					t_form;

void				ft_takefile(t_form *form, char *name);
int					ft_strlenarray(char **ar);
void				ft_take_array_struct(t_form *form, char *name);
t_crd				*ft_return_coord(int x, int y, char *z);
int					key(int key, t_form *form);
void				ft_draw_line(t_crd *crd1, t_crd *crd2, t_form *form);
void				ft_print_form(t_form *form);
void				ft_img(t_form *form, int i, int j);
void				ft_tocenter(t_form *form);
void				ft_turn_x(t_form *form, int r);
void				ft_turn_y(t_form *form, int r);
void				ft_turn_z(t_form *form, int r);
void				ft_zoom(t_form *form, int r, int i, int j);
void				ft_toisometric(t_form *form);
void				ft_draw(t_crd *crd1, t_crd *crd2, t_form *form);
void				ft_error(int i);
int					ft_check(char *s);
void				ft_color(t_form *form);
#endif
