#include "libgfx.h"

t_vector        vector_add(t_vector a, t_vector b)
{
        return (gfx_new_vector(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vector        vector_sub(t_vector a, t_vector b)
{
        return (gfx_new_vector(a.x - b.x, a.y - b.y, a.z - b.z));
}

t_vector        vector_divide(t_vector a, float b)
{
        return (gfx_new_vector(a.x / b, a.y / b, a.z / b));
}

t_vector        vector_mult(t_vector a, float b)
{
        return (gfx_new_vector(a.x * b, a.y * b, a.z * b));
}

float           vector_dot(t_vector a, t_vector b)
{
        return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

float           vector_len(t_vector a)
{
        return (sqrt(a.x * a.x) + (a.y * a.y) + (a.z * a.z));
}

t_vector        vector_normalize(t_vector a)
{
        float len;

        len = vector_len(a);
        return (gfx_new_vector(a.x / len, a.y / len, a.z / len));
}

void    matrix_string(t_matrix matrix)
{
        char *str;

        str = ft_sprintf("%s %s %s %s %s %s",
        "M | vtcX | vtcY | vtcZ | vtxO\n",
        "-----------------------------\n",
        "x | %0.2f | %0.2f | %0.2f | %0.2f\n",
        "y | %0.2f | %0.2f | %0.2f | %0.2f\n",
        "z | %0.2f | %0.2f | %0.2f | %0.2f\n",
        "w | %0.2f | %0.2f | %0.2f | %0.2f\n");

        printf(str,
                matrix.v[0][0], matrix.v[0][1], matrix.v[0][2], matrix.v[0][3],
                matrix.v[1][0], matrix.v[1][1], matrix.v[1][2], matrix.v[1][3],
                matrix.v[2][0], matrix.v[2][1], matrix.v[2][2], matrix.v[2][3],
                matrix.v[3][0], matrix.v[3][1], matrix.v[3][2], matrix.v[3][3]
        );
        ft_strdel(&str);
}

t_matrix        matrix_empty(void)
{
        t_matrix mat;

        for (int y = 0; y < 4; y++)
        {
                for (int x = 0; x < 4; x++)
                {
                        mat.v[y][x] = 0.0f;
                }
        }
        return (mat);
}

t_matrix        matrix_mult(t_matrix this, t_matrix rhs)
{
        t_matrix mat;

        for (int i = 0; i < 4; i++)
        {
                for (int j = 0; j < 4; j++)
                {
                        mat.v[i][j] = 0;
                        for (int k = 0; k < 4; k++)
                        {
                                mat.v[i][j] += this.v[i][k] * rhs.v[k][j];
                        }
                }
        }
        return (mat);
}

// set scale to one for identity matrix
t_matrix        matrix_scale(float scale)
{
        t_matrix mat;

        mat = matrix_empty();
        mat.v[0][0] = scale;
        mat.v[1][1] = scale;
        mat.v[2][2] = scale;
        mat.v[3][3] = 1;
        return (mat);
}

t_matrix matrix_rotate_x(float angle) // in degrees
{
        t_matrix matrix;

        matrix = matrix_scale(1);
        matrix.v[0][0] = 1.0f;
        matrix.v[1][1] = cos(angle);
        matrix.v[1][2] = -sin(angle);
        matrix.v[2][1] = sin(angle);
        matrix.v[2][2] = cos(angle);
        return (matrix);
}

t_matrix        matrix_rotate_y(float angle)
{
        t_matrix matrix;

        matrix = matrix_scale(1);
        matrix.v[0][0] = cos(angle);
        matrix.v[0][2] = sin(angle);
        matrix.v[1][1] = 1;
        matrix.v[2][0] = -sin(angle);
        matrix.v[2][2] = cos(angle);
        return (matrix);
}

t_matrix        matrix_rotate_z(float angle)
{
        t_matrix matrix;

        matrix = matrix_scale(1);
        matrix.v[0][0] = cos(angle);
        matrix.v[0][1] = -sin(angle);
        matrix.v[1][0] = sin(angle);
        matrix.v[1][1] = cos(angle);
        matrix.v[2][2] = 1;
        return (matrix);
}


t_matrix        matrix_translate(t_vector vtc)
{
        // doesnt work, no idea what matrix.vtx0 is
        t_matrix matrix;

        matrix = matrix_scale(1);
        matrix.v[0][3] = vtc.x;
        matrix.v[1][3] = vtc.y;
        matrix.v[2][3] = vtc.z;
        return (matrix);
}



t_matrix        matrix_projection(float fov, float ratio, float near, float far)
{
        t_matrix matrix;

        matrix = matrix_scale(1);
        matrix.v[1][1] = 1 / tan(0.5 * (fov * M_PI / 180));//deg2rad(fov));
        matrix.v[0][0] = matrix.v[1][1] / ratio;
        matrix.v[2][2] = -1 * (-near - far) / (near - far);
        matrix.v[3][2] = -1;
        matrix.v[2][3] = (2 * near * far) / (near - far);
        matrix.v[3][3] = 0;
        return (matrix);
}

t_vector        matrix_vector_transform(t_matrix matrix, t_vector vector)
{
        // return (gfx_new_vector(
        //                      (vector.x * matrix.v[0][0]) +
        //                      (vector.y * matrix.v[0][1]) +
        //                      (vector.z * matrix.v[0][2]),

        //                      (vector.x * matrix.v[1][0]) +
        //                      (vector.y * matrix.v[1][1]) +
        //                      (vector.z * matrix.v[1][2]),

        //                      (vector.x * matrix.v[2][0]) +
        //                      (vector.y * matrix.v[2][1]) +
        //                      (vector.z * matrix.v[2][2])));
        t_vector v;

        v.x = (vector.x * matrix.v[0][0]) + (vector.y * matrix.v[0][1]) + (vector.z * matrix.v[0][2]) ;//+ (vector.w * matrix.v[3]);
        v.y = (vector.x * matrix.v[1][0]) + (vector.y * matrix.v[1][1]) + (vector.z * matrix.v[1][2]) ;//+ (vector.w * matrix.v[7]);
        v.z = (vector.x * matrix.v[2][0]) + (vector.y * matrix.v[2][1]) + (vector.z * matrix.v[2][2]);//+ (vector.w * matrix.v[11]);
        return (v);
        //v.w = vector.x * matrix.v[11]) + (vector.y* matrix.v[13])+ (vector.z * matrix.v[14]);//+ (vector.w * matrix.v[15]);
                                //x = (vector.w * $this->matrix[0][3])
                                //y =   (vector.getW() * $this->matrix[1][3]),
                                //z=            (vector.getW() * $this->matrix[2][3])));
                                // .w = (vector.getX() * $this->matrix[3][0]) +
                                //              (vector.getY() * $this->matrix[3][1]) +
                                //              (vector.getZ() * $this->matrix[3][2]) +
                                //              (vector.getW() * $this->matrix[3][3])
                                // )));
}
