/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:45:43 by vmormont          #+#    #+#             */
/*   Updated: 2019/07/31 00:57:49 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		find_color(t_fdf * all, int x, int y)
{
	all->color = BLUE_LIGHT;
	if (all->map[y][x] > 0 || (x + 1 < all->row && all->map[y][x + 1] > 0))
		all->color = RED;
	if (all->map[y][x] > 0 || (y + 1 < all->col && all->map[y + 1][x] > 0))
		all->color = RED;
	if (all->map[y][x] < 0 || (x + 1 < all->row && all->map[y][x + 1] < 0))
		all->color = RED;
	if (all->map[y][x] < 0 || (y + 1 < all->col && all->map[y + 1][x] < 0))
		all->color = RED;
}

int         check_color(char *line)
{
    int		offset;

    offset = 0;
    if (*line && *line++ != '0')
		end("error: invalid coloring map\n");
    if (*line && *line++ != 'x')
		end("error: invalid coloring map\n");
    while (*line && *line != ' ')
	{
		if ((*line < '0' || *line > '9') && (*line < 'A' || *line > 'F')
				&& (*line < 'a' || *line > 'f'))
			end("error: invalid coloring map\n");
			line++;
			offset++;
	}
	if (offset < 2 || offset > 6)
		end("error: invalid coloring map\n");
	return (offset);
}
