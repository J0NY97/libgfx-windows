/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:31:50 by nneronin          #+#    #+#             */
/*   Updated: 2020/09/26 18:45:41 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

void	gfx_draw_rect(SDL_Surface *surface, Uint32 color, t_xywh dim)
{
	gfx_draw_line(surface, color, (t_vector){dim.x, dim.y, 0}, (t_vector){dim.x + dim.w, dim.y, 0});
	gfx_draw_line(surface, color, (t_vector){dim.x, dim.y, 0}, (t_vector){dim.x, dim.y + dim.h, 0});
	gfx_draw_line(surface, color, (t_vector){dim.x + dim.w, dim.y, 0}, (t_vector){dim.x + dim.w, dim.y + dim.h, 0});
	gfx_draw_line(surface, color, (t_vector){dim.x, dim.y + dim.h, 0}, (t_vector){dim.x + dim.w, dim.y + dim.h, 0});
}
