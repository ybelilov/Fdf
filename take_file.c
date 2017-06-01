/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybelilov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 19:10:14 by ybelilov          #+#    #+#             */
/*   Updated: 2017/03/05 19:10:16 by ybelilov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_takefile(t_form *form, char *name)
{
	int		fd;
	char	*line;

	form->lenmapy = 0;
	form->col = 0;
	line = ft_strnew(1);
	fd = open(name, O_RDONLY);
	read(fd, line, 0) == -1 ? ft_error(2) : 0;
	while (read(fd, line, 1) > 0)
		if (line[0] == '\n')
			form->lenmapy++;
	free(line);
	close(fd);
	form->crd = (t_crd***)malloc(sizeof(t_crd**) * form->lenmapy);
	ft_take_array_struct(form, name);
}

void	ft_take_array_struct(t_form *form, char *name)
{
	int		fd;
	int		i;
	int		j;
	char	**ar;
	char	*line;

	fd = open(name, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &line) == 1)
	{
		j = -1;
		ar = ft_strsplit(line, ' ');
		if (ft_strlenarray(ar) != form->lenmapx && i != 0)
			ft_error(1);
		form->lenmapx = ft_strlenarray(ar);
		form->crd[i] = (t_crd**)malloc(sizeof(t_crd*) * form->lenmapx);
		while (ar[++j])
			form->crd[i][j] = ft_return_coord(j, i, ar[j]);
		i++;
		free(ar);
		free(line);
	}
	close(fd);
}

t_crd	*ft_return_coord(int x, int y, char *z)
{
	t_crd	*a;

	a = (t_crd*)malloc(sizeof(t_crd));
	a->x = x;
	a->y = y;
	a->z = atoi(z);
	free(z);
	return (a);
}
