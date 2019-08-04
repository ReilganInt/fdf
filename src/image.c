/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:23:03 by vmormont          #+#    #+#             */
/*   Updated: 2019/08/02 23:23:05 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		push_pixel(t_fdf *all, int x, int y)
{
	if (x >= 0 && x < MAX_X && y >= 0 && y < MAX_Y)
		*(unsigned int *)(all->data + (x * (all->bpp)) + (y * all->sl)) = all->color;
}

void		bresenkham_hor(t_point *p, t_fdf *all, int x, int y)
{
	p->x1 = all->x + (x - y) * all->z + all->px;
	p->y1 = all->y + (x + y) * all->z - (all->map[y][x] * 2) + all->py;
	p->x2 = all->x + ((x + 1) - y) * all->z + all->px;
	p->y2 = all->y + ((x + 1) + y) * all->z - (all->map[y][x + 1] * 2) + all->py;
	p->dx = (float)(p->x2 - p->x1);
	p->dy = (float)(p->y2 - p->y1);
}

void		bresenkham_ver(t_point *p, t_fdf *all, int x, int y)
{
	p->x1 = all->x + (x - y) * all->z + all->px;
	p->y1 = all->y + (x + y) * all->z - (all->map[y][x] * 2) + all->py;
	p->x2 = all->x + (x - (y + 1)) * all->z + all->px;
	p->y2 = all->y + (x + (y + 1)) * all->z - (all->map[y + 1][x] * 2) + all->py;
	p->dx = (float)(p->x2 - p->x1);
	p->dy = (float)(p->y2 - p->y1);
}

void		bresenkham(t_fdf *all, int x, int y)
{
	t_point	p;
	double	temp;
	int		i;
	int		j;

	temp = 0.0;
	if (x < all->row - 1)
		 bresenkham_hor(&p, all, x, y);
	while (temp <= 1 && x < all->row - 1)
	{
		i = p.x1 + (p.dx * temp);
		j = p.y1 + (p.dy * temp);
		push_pixel(all, i, j);
		temp += 1. / sqrt((p.dx * p.dx) + (p.dy * p.dy));
	}
	temp = 0.0;
	if (x < all->row - 1)
		 bresenkham_ver(&p, all, x, y);
	while (temp <= 1 && y < all->col - 1)
	{
		i = p.x1 + (p.dx * temp);
		j = p.y1 + (p.dy * temp);
		push_pixel(all, i, j);
		temp += 1. / sqrt((p.dx * p.dx) + (p.dy * p.dy));
	}
}

int			fill_img(t_fdf *all)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	chenge_z(all);
	all->x = (MAX_X / 2) - (all->row * all->z) / 2;
	all->y = (MAX_Y / 2) - (all->col * all->z) / 2;
	while (y < all->col)
	{
		while (x < all->row)
		{
			find_color(all, x, y);
			set_coord(all, x, y);
			x++;
		}
		y++;
		x = 0;
	}
	mlx_put_image_to_window(all->mlx_ptr, all->win_prt, all->img_ptr, 0, 0);
	return (1);
}
