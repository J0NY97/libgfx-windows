/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gfx_draw_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:31:50 by nneronin          #+#    #+#             */
/*   Updated: 2021/07/25 14:22:53 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

static inline int	sign(float a, float b)
{
	if (a < b)
		return (1);
	return (-1);
}

static inline void	line_calc(t_vector v1, t_vector v2,
		int *cath_x, int *cath_y)
{
	if (((int)v2.y - (int)v1.y) < 0)
		*cath_x = ((int)v2.y - (int)v1.y) * -1;
	else
		*cath_x = ((int)v2.y - (int)v1.y);
	if (((int)v2.x - (int)v1.x) < 0)
		*cath_y = ((int)v2.x - (int)v1.x) * -1;
	else
		*cath_y = ((int)v2.x - (int)v1.x);
}

void	gfx_draw_line(SDL_Surface *surf, Uint32 color, t_vector v1, t_vector v2)
{
	int			cath_x;
	int			cath_y;
	int			overflow_x;
	int			overflow_y;

	line_calc(v1, v2, &cath_x, &cath_y);
	overflow_y = cath_y - cath_x;
	while ((int)v1.x != (int)v2.x || (int)v1.y != (int)v2.y)
	{
		set_pixel(surf, (int)v1.x, (int)v1.y, color);
		overflow_x = overflow_y * 2;
		if (overflow_x > -(cath_x))
		{
			overflow_y -= cath_x;
			v1.x += sign(v1.x, v2.x);
		}
		else if (overflow_x < cath_x)
		{
			overflow_y += cath_y;
			v1.y += sign(v1.y, v2.y);
		}
	}
}
