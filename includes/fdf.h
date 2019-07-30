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

# define ABS(x) (x > 0 ? x : -x)
# define TORF(y) (y > 0 ? 1 : -1)

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	int				color;
}					t_point;

typedef struct		s_vector
{
	t_point			p1;
	t_point			p2;
}					t_vector;

typedef struct		s_fdf
{
	void			*mlx_ptr;
	void			*win_prt;
	void			*img_ptr;
	int				**grid;
	t_point			*grid_size;

}					t_fdf;


#endif
