#include "libgfx.h"

t_vector gfx_vector_sub(t_vector v, float n)
{
	return ((t_vector){v.x - n, v.y - n, v.z - n});
}
