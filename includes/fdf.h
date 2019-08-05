/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmormont <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 16:25:54 by vmormont          #+#    #+#             */
/*   Updated: 2019/06/04 16:42:13 by vmormont         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <math.h>
# define MAX_X 1800
# define MAX_Y 1000
# define WHITE 0xFFFFFF
# define GREEN 0x008080
# define BLUE_LIGHT 0x00BFFF
# define BLUE 0x0901F7
# define RED 0xFE4D01
# define M_HARD 0x4682B4
# define M_MEDIUM 0x7FFFD4
# define ZERRO 0xFFFFE0
# define P_MEDIUM 0x00FF7F
# define P_HARD 0xADFF2F

typedef struct		s_point
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				z;
	float			dx;
	float			dy;
}					t_point;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_prt;
	void			*img_ptr;
	char			*data;
	int				bpp;
	int				sl;
	int				edi;
	int				**map;
	int				x;
	int				y;
	int				z;
	int				row;
	int				col;
	int				px;
	int				py;
	int				height;
	int				color;
}					t_fdf;

void				instructions(t_fdf *all);
void				end(char *error);
void				new_point(t_fdf *all);
void				new_image(t_fdf *all);
void				init_all(t_fdf *all);
int					main(int argc, char **argv);
int					key_hook(int keycode, t_fdf *all);
void				check_key(int keycode, t_fdf *all);
void				check_key2(int keycode, t_fdf *all);
int					check_line(char *line);
int					validation(int fd);
void				push_pixel(t_fdf *all, int x, int y);
void				bresenkham_hor(t_point *p, t_fdf *all, int x, int y);
void				bresenkham_ver(t_point *p, t_fdf *all, int x, int y);
void				bresenkham(t_fdf *all, int x, int y);
int					fill_img(t_fdf *all);
void				chenge_z(t_fdf *all);
int					fill_nbr(char *map);
int					*fill_line(char **map, int j);
t_fdf				*fill_all(int fd, int maxy, t_fdf *all);
void				find_color(t_fdf *all, int x, int y);
int					check_color(char *line);
void				free_tab(int **tab, int i);
void				free_split(char **tab, int max);

#endif
