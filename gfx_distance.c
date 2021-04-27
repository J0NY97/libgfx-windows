/* ************************************************************************** */
/*                                                                            */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsalmi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 12:27:49 by jsalmi            #+#    #+#             */
/*   Updated: 2020/09/30 13:02:56 by jsalmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgfx.h"

double	gfx_distance(t_vector v1, t_vector v2)
{
	double result;

	result = sqrt(ft_pow(v1.x - v2.x, 2) + ft_pow(v1.y - v2.y, 2) + ft_pow(v1.z - v2.z, 2));
	return (result > 0 ? result : -result);
}
