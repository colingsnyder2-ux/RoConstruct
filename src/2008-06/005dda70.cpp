// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Vector3
{
    float x, y, z;
};

struct Matrix3
{
    float data[9];

    Matrix3(float, float, float,
            float, float, float,
            float, float, float);

    Matrix3 operator+(const Matrix3&) const;
};

Matrix3 operator*(float, const Matrix3&);

Matrix3 displacementMatrix(const Vector3& a, const Vector3& b,
                           const Matrix3& base, float scale)
{
    double x = double(b.x) - a.x;
    double y = double(b.y) - a.y;
    double z = double(b.z) - a.z;

    double xx = x * x;
    double yy = y * y;
    double zz = z * z;
    double xy = x * y;
    double xz = x * z;
    double yz = y * z;

    return base + scale * Matrix3(
        float(yy + zz), float(-xy),     float(-xz),
        float(-xy),     float(xx + zz), float(-yz),
        float(-xz),     float(-yz),     float(xx + yy));
}
