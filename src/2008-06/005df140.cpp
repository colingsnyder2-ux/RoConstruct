// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3(float, float, float);
};

Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c) {
}

struct Matrix3 {
    float elements[9];
    static Matrix3 __cdecl fromAxisAngle(const Vector3&, float);
    Matrix3 operator*(const Matrix3&) const;
};

void __cdecl rotate(Matrix3& matrix, float angle) {
    static const Vector3 axis(0.0f, 1.0f, 0.0f);
    Matrix3 rotation = Matrix3::fromAxisAngle(axis, angle);
    matrix = rotation * matrix;
}
