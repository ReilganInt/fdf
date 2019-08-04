/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 00:58:07 by vmormont          #+#    #+#             */
/*   Updated: 2019/07/31 00:58:09 by vmormont         ###   ########.fr       */
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
			*line++;
		if (*line || *line < '0' || *line > '9')
			end("error: invalid map\n");
		while (*line && *line >= '0' && *line <= '9')
			line++;
		if (*line == ',')
			line += check_color(&(*line++));
		len++;
		if (!(*line))
			break ;
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
	while((temp = get_next_line(fd, &line)))
	{
		len1 = check_line(line);
		ft_memdel((void **)&line);
		if (maxy > 0 && len1 != len2)
			end("error: invalid length map\n");
		len2 = len1;
		maxy++;
	}
	if (temp == -1)
		end("error: unable get_next_line\n");
	ft_memdel((void **)&line);
	return (maxy);
}
