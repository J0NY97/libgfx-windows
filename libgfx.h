/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:44:05 by jsalmi            #+#    #+#             */
/*   Updated: 2021/04/27 10:57:59 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGFX_H
# define LIBGFX_H
# include "../libft-windows/libft.h"
# include "../better_libui-windows/better_libui.h"
# include "../ft_printf-windows/ft_printf.h"
# include <math.h>

typedef	struct	s_vector		t_vector;

struct				s_vector
{
	double			x;
	double			y;
	double			z;
};

t_vector			gfx_new_vector(double x, double y, double z);
void				gfx_vector_string(t_vector v);

int					gfx_vector_dot(t_vector curr, t_vector v1, t_vector v2); // should probably return double
double				gfx_distance(t_vector v1, t_vector v2);
t_vector			gfx_vector_multiply(t_vector v, int mult);

void				gfx_draw_vector(SDL_Surface *surface, Uint32 color, unsigned int size, t_vector v);
void				gfx_draw_line(SDL_Surface *surf, Uint32 color, t_vector v1, t_vector v2);
void				gfx_draw_rect(SDL_Surface *surface, Uint32 color, t_xywh dim);
void				gfx_raster(SDL_Surface *surf, Uint32 color, int x0, int x1, int y0);

int					gfx_hitbox_square(int x, int y, t_xywh rect);

// Matrix math and vector math.

typedef struct  s_matrix
{
        float           v[4][4];
}                               t_matrix;

t_vector	vector_add(t_vector a, t_vector b);
t_vector	vector_sub(t_vector a, t_vector b);
t_vector	vector_divide(t_vector a, float b);
t_vector	vector_mult(t_vector a, float b);
float		vector_dot(t_vector a, t_vector b);
float		vector_len(t_vector a);
t_vector	vector_normalize(t_vector a);
void		matrix_string(t_matrix matrix);
t_matrix	matrix_empty(void);
t_matrix	matrix_mult(t_matrix this, t_matrix rhs);
t_matrix	matrix_scale(float scale);
t_matrix	matrix_rotate_x(float angle);
t_matrix	matrix_rotate_y(float angle);
t_matrix	matrix_rotate_z(float angle);
t_matrix	matrix_translate(t_vector vtc);
t_matrix	matrix_projection(float fov, float ratio, float near, float far);
t_vector	matrix_vector_transform(t_matrix matrix, t_vector vector);

#endif
