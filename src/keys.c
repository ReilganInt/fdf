/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 22:50:14 by vmormont          #+#    #+#             */
/*   Updated: 2019/08/02 22:50:16 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		check_key(int keycode, t_fdf *all)
{
	if (keycode == 53)
	{
		free_tab(all->map, all->col);
		exit(EXIT_FAILURE);
	}
	if (keycode == 47)
		all->height = 1;
	if (keycode == 43)
		all->height = -1;
	if (keycode == 126)
		all->py -= 10;
	if (keycode == 125)
		all->py += 10;
	if (keycode == 124)
		all->px += 10;
	if (keycode == 123)
		all->px -= 10;
	if (keycode == 69)
		all->z += 1;
	if (keycode == 78)
		if (all->z > 1)
			all->z -= 1;
}

int			key_hook(int keycode, t_fdf *all)
{
	check_key(keycode, all);
	mlx_destroy_image(all->mlx_ptr, all->img_ptr);
	new_image(all);
	mlx_clear_window(all->mlx_ptr, all->win_prt);
	fill_img(all);
	return (0);
}
