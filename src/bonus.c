/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:45:50 by vmormont          #+#    #+#             */
/*   Updated: 2019/05/31 16:45:53 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		instructions(t_fdf *all)
{
	mlx_string_put(all->mlx_ptr, all->win_prt, 50, 50, 0xFFFFE0, "Welcome");
	mlx_string_put(all->mlx_ptr, all->win_prt, 50, 75, 0xFFFFE0, "ESC");
	mlx_string_put(all->mlx_ptr, all->win_prt, 50, 100, 0xFFFFE0, "< and >");
	mlx_string_put(all->mlx_ptr, all->win_prt, 50, 125, 0xFFFFE0, "+ and -");
	mlx_string_put(all->mlx_ptr, all->win_prt, 50, 150, 0xFFFFE0,
															"up and down");
	mlx_string_put(all->mlx_ptr, all->win_prt, 50, 175, 0xFFFFE0,
														"right and left");
}

void		free_tab(int **tab, int i)
{
	int		j;

	j = 0;
	while (j < i)
	{
		free((void *)tab[j]);
		j++;
	}
	free(tab);
}

void		free_split(char **tab, int max)
{
	int		i;

	i = 0;
	while (tab[i] && i < max)
		free(tab[i++]);
	free(tab);
}
