// from server: 100% by king_originala
extern "C" double __cdecl sin(double);
extern "C" double __cdecl cos(double);
#pragma intrinsic(sin, cos)
#pragma float_control(precise, off)

struct Vector {
    float x, y, z;
};

struct Matrix {
    float elements[9];

    Matrix(const Matrix&);
    static const Matrix& __cdecl identity();
    void setColumn(int, const Vector&);
    Matrix operator*(const Matrix&) const;
};

Matrix __cdecl rotate(const Matrix& source, float angle)
{
    Matrix rotation(Matrix::identity());

    float s = (float)sin(angle);
    float c = (float)cos(angle);

    Vector column = { c, s, 0.0f };
    rotation.setColumn(0, column);

    column.x = -s;
    column.y = c;
    column.z = 0.0f;
    rotation.setColumn(1, column);

    return source * rotation;
}
