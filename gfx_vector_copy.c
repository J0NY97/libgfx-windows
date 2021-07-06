#include "libgfx.h"

t_vector	gfx_vector_copy(t_vector v)
{
	return (gfx_new_vector(v.x, v.y, v.z));
}
