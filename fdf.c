/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:09:36 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/05 19:09:38 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_form	form;

	if (ac != 2)
		return (0);
	form.mlx_ptr = mlx_init();
	form.window = mlx_new_window(form.mlx_ptr, 1000, 1000, "Lets begin");
	ft_takefile(&form, av[1]);
	ft_toisometric(&form);
	ft_print_form(&form);
	mlx_hook(form.window, 2, 0, key, &form);
	mlx_loop(form.mlx_ptr);
	return (0);
}
