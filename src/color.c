/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:03:24 by vmormont          #+#    #+#             */
/*   Updated: 2019/08/05 18:03:26 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		find_color(t_fdf *all, int x, int y)
{
	all->color = ZERRO;
	if ((all->map[y][x] > 0 && (all->map[y][x] <= 100)) || ((x + 1 < all->row
		&& all->map[y][x + 1] > 0) && (all->map[y][x + 1] <= 100)))
		all->color = P_MEDIUM;
	if ((all->map[y][x] > 0 && (all->map[y][x] <= 100)) || ((y + 1 < all->col
		&& all->map[y + 1][x] > 0) && (all->map[y + 1][x] <= 100)))
		all->color = P_MEDIUM;
	if ((all->map[y][x] > 0 && (all->map[y][x] > 100)) || ((x + 1 < all->row
		&& all->map[y][x + 1] > 0) && (all->map[y][x + 1] > 100)))
		all->color = P_HARD;
	if ((all->map[y][x] > 0 && (all->map[y][x] > 100)) || ((y + 1 < all->col
		&& all->map[y + 1][x] > 0) && (all->map[y + 1][x] > 100)))
		all->color = P_HARD;
	if ((all->map[y][x] < 0 && (all->map[y][x] >= -100)) || ((x + 1 < all->row
		&& all->map[y][x + 1] < 0) && (all->map[y][x + 1] >= -100)))
		all->color = M_MEDIUM;
	if ((all->map[y][x] < 0 && (all->map[y][x] >= -100)) || ((y + 1 < all->col
		&& all->map[y + 1][x] < 0) && (all->map[y + 1][x] >= -100)))
		all->color = M_MEDIUM;
	if ((all->map[y][x] < 0 && (all->map[y][x] < -100)) || ((x + 1 < all->row
		&& all->map[y][x + 1] < 0) && (all->map[y][x + 1] < -100)))
		all->color = M_HARD;
	if ((all->map[y][x] < 0 && (all->map[y][x] < -100)) || ((y + 1 < all->col
		&& all->map[y + 1][x] < 0) && (all->map[y + 1][x] < -100)))
		all->color = M_HARD;
}

int			check_color(char *line)
{
	int	offset;

	offset = 0;
	if (*line && *line != '0')
		end("error: invalid coloring map");
	line++;
	if (*line && *line != 'x')
		end("error: invalid coloring map");
	line++;
	while (*line && *line != ' ')
	{
		if ((*line < '0' || *line > '9') && (*line < 'A' || *line > 'F')
			&& (*line < 'a' || *line > 'f'))
			end("error: invalid coloring map");
		line++;
		offset++;
	}
	if (offset < 2 || offset > 6)
		end("error: invalid coloring map");
	return (offset);
}
