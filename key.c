/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:09:47 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/05 19:09:49 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key(int key, t_form *form)
{
	if (key == 53)
		exit(1);
	else if (key == 89 || key == 86)
		ft_turn_x(form, key % 2 == 0 ? -1 : 1);
	else if (key == 91)
		ft_turn_y(form, 1);
	else if (key == 92)
		ft_turn_z(form, 1);
	else if (key == 87)
		ft_turn_y(form, -1);
	else if (key == 88)
		ft_turn_z(form, -1);
	else if (key == 125 || key == 126)
		ft_zoom(form, key % 2 == 0 ? 1 : -1, 0, 0);
	else if (key == 36)
		ft_color(form);
	return (0);
}
