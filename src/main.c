/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:19:29 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/04 16:46:34 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

#include "fdf.h"

// void				set_point(void *buffer, int x, int y)
// {
	
// }

// int					end(char *str)
// {
// 	ft_putendl(str);
// 	return (1);
// }

// void				set_line(void *buffer, t_point *p0, t_point *p1)
// {
// 	int				deltaX;
// 	int				deltaY;
// 	int				accretion;
// 	int				dicretion;
// 	int				x;
// 	int				y;

// 	ft_putendl((char *)buffer);

	deltaX = p1->x - p0->x;
	deltaY = p1->y - p0->y;
	accretion = 0;
	if (ABS(deltaX) >= ABS(deltaY))
	{
		y = p0->y;
		dicretion = deltaY != 0 ? TORF(deltaY) : 0;
		x = p0->x;
		while (deltaX > 0 ? x <= p1->x : x >= p1->x)
		{
			set_point(buffer, x, y);
			accretion += ABS(deltaY);
			if (accretion >= ABS(deltaX))
			{
				 accretion -= ABS(deltaX);
				 y += dicretion;
			}
			deltaX > 0 ? x++: x--;
		}
	}
	else
	{
		x = p0->x;
		dicretion = deltaX != 0 ? TORF(deltaX) : 0;
		y = p0->y;
		while (deltaY > 0 ? y <= p1->y : y >= p1->y)
		{
			set_point(buffer, x, y);
			accretion += ABS(deltaX);
			if (accretion >= ABS(deltaY))
			{
				accretion -= ABS(deltaY);
				y += dicretion;
			}
			deltaY > 0 ? y++ : y--;
		}
	}
}

int					**get_grid(int fd, t_fdf *allin);
{
	int				i;
	int				j;
	char			*line;
	char			*tmp;
	int				**grid;

	i = 0;
	grid = (int **)malloc(sizeof(int) * allin->grid_size->y + 1);
	while ((get_next_line(fd, &line)) > 0)
	{
		j = 0;
		tmp = ft_strsplit(line, ' ');
		grid[i] = (int *)ft_memalloc(ft_strlen(tmp) + 1);
		while (tmp[j])
		{
			grid[i][j] = ft_atoi(tmp[j]);
			j++;
		}
		allin->grid_size->x = j;
		i++;
		free(line);
	}
	return (grid);
}

t_fdf				*get_all(int argv, )
{
	t_fdf			*allin;
	int				fd;
	int				i;
	char			*line;

	
	if ((fd = open(argv, O_RDONLY) < 0))
		return (NULL);
	while ((get_next_line(fd, &line)) > 0)
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(argv, O_RDONLY);
	allin->mlx_ptr = mlx_init();
	allin->win_prt = mlx_new_window(allin->mlx_ptr, 1800, 1500, "FdF 42");
	allin->img_ptr = mlx_new_image(allin->mlx_ptr, 1400, 1200);
	allin->grid_size->y = i;
	allin->grid = get_grid(fd, allin);
	return (allin);
}

int					end(char *error)
{
	ft_putendl(error);
	return (1);
}

int					main(int argc, char **argv)
{
	t_fdf			*allin;

	if (argc != 2)
		return (end("usage ./fdf [map]"));
	if (!(allin = get_all(argv[1], )))
		return (end("invalid map"));

	mlx_key_hook(allin->win_prt, , );
	mlx_mouse_hook(allin->win_prt, , );
	mlx_loop(allin->mlx_ptr);
	return (0);
}
