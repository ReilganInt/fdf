/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 18:08:32 by vmormont          #+#    #+#             */
/*   Updated: 2019/08/05 18:08:33 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_line(char *line)
{
	int		len;

	len = 0;
	while (*line)
	{
		while (*line && *line == ' ')
			line++;
		if (*line && *line == '-')
			line++;
		if (!*line || *line < '0' || *line > '9')
			end("error: invalid map");
		while (*line != '\0' && *line >= '0' && *line <= '9')
			line++;
		if (!(*line))
			break ;
		if (*line == ',' && line++)
			line += check_color(&(*line)) + 3;
		len++;
	}
	return (len);
}

int			validation(int fd)
{
	int		maxy;
	int		len1;
	int		len2;
	int		temp;
	char	*line;

	len1 = 0;
	len2 = 0;
	maxy = 0;
	while ((temp = get_next_line(fd, &line)) == 1)
	{
		len1 = check_line(line);
		ft_memdel((void **)&line);
		if ((len1 != len2 && maxy > 0))
			end("error: invalid length map");
		len2 = len1;
		maxy++;
	}
	if ((temp == -1) || maxy == 0)
		end("error: unable get_next_line");
	ft_memdel((void **)&line);
	return (maxy);
}
