/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:19:29 by vmormont          #+#    #+#             */
/*   Updated: 2019/07/31 00:58:02 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gcc -I /usr/local/include main.c -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

#include "fdf.h"

void		end(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

void		new_point(t_fdf *all)
{
	all->px = 0;
	all->py = 0;
	all->ha = 0;
}

void		new_image(t_fdf *all)
{
	all->img_ptr =	mlx_new_image(all->mlx_ptr, MAX_X, MAX_Y);
	all->data = mlx_get_data_addr(all->img_ptr, &all->bpp, &all->sl, &all->edi);
	if (!(all->data))
		end("error: unable to create image\n");
	all->bpp /= 8;
}

void		init_all(t_fdf *all)
{
	all->mlx_ptr = mlx_init();
	all->win_prt = mlx_new_window(all->mlx_ptr, MAX_X, MAX_Y, "fdf project");
	new_point(all);
	new_image(all);
}

int			main(int argc, char **argv)
{
	int		maxy;
	int		fd;
	t_fdf	all;

	if (argc != 2)
		end("usage: ./fdf your_map\n");
	if (!(fd = open(argv[1], O_RDONLY)))
		end("error: unable to open file\n");
	maxy = validation(fd);
	close(fd);
	if (!(fd = open(argv[1], O_RDONLY)))
		end("error: unable to open file\n");
	fill_all(fd, maxy, &all);
	init_all(&all);
	if (all.row > 50)
		all.z = 2;
	fill_img(&all);
	mlx_hook(all.win_prt, 2, 1, key_hook, &all);
	mlx_loop(all.mlx_ptr);
	return (1);
}
