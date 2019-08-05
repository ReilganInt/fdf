/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:46:08 by vmormont          #+#    #+#             */
/*   Updated: 2019/07/31 00:57:54 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		chenge_z(t_fdf *all)
{
	int		i;
	int		j;

	i = 0;
	while (i < all->col)
	{
		j = 0;
		while (j < all->row)
		{
			if (all->map[i][j] == -1 && all->height == 1)
				all->map[i][j] += 3;
			else if (all->map[i][j] == 1 && all->height == -1)
				all->map[i][j] -= 3;
			else if (all->map[i][j] != 0)
				all->map[i][j] += all->height;
			j++;
		}
		i++;
	}
	all->height = 0;
}

int			fill_nbr(char *map)
{
	int		nbr;

	nbr = 0;
	if (*map && *map == '0')
		nbr = 0;
	else if (*map && *map > '0' && *map <= '9')
		nbr = ft_atoi(&(*map));
	return (nbr);
}

int			*fill_line(char **map, int j)
{
	int		i;
	int		*tab;

	i = 0;
	tab = NULL;
	if (!(tab = (int *)malloc(sizeof(int) * j)))
		end("error: memory cannot be allocated");
	while (map[i] && i < j)
	{
		tab[i] = fill_nbr(map[i]);
		i++;
	}
	return (tab);
}

t_fdf		*fill_all(int fd, int maxy, t_fdf *all)
{
	int		i;
	int		j;
	char	*line;
	char	**map;
	int		**tab;

	i = 0;
	j = 0;
	all->col = maxy;
	if (!(tab = (int **)malloc(sizeof(int *) * maxy)))
		end("error: memory cannot be allocated");
	while (get_next_line(fd, &line) && i < maxy)
	{
		map = ft_strsplit(line, ' ');
		if (!i)
			while (map[j])
				j++;
		tab[i++] = fill_line(map, j);
		free_split(map, j);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&line);
	all->map = tab;
	all->row = j;
	return (all);
}
