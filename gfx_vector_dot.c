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

int		gfx_vector_dot(t_vector curr, t_vector v1, t_vector v2)
{
	int v1x;
	int v1y;
	int v2x;
	int v2y;
	int	dot;

	v1x = curr.x - v1.x;
	v1y = curr.y - v1.y;
	v2x = v2.x - v1.x;
	v2y = v2.y - v1.y;
	dot = v1x * v2y - v1y * v2x;
	return (dot);
}
