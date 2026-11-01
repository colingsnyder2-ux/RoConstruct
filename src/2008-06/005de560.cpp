// from server: 100% by king_originala
extern "C" double __cdecl fabs(double);

struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float m[9];
};

int __cdecl classify(const Vector3& v, const Matrix3& m)
{
    double x = v.x * m.m[0] + (m.m[3] * v.y + m.m[6] * v.z);
    double y = m.m[1] * v.x + m.m[4] * v.y + m.m[7] * v.z;
    double z = m.m[2] * v.x + m.m[5] * v.y + m.m[8] * v.z;

    double ax = fabs(x);
    double ay = fabs(y);
    double az = fabs(z);

    if (ax > ay) {
        if (ax > az)
            return x > 0.0 ? 0 : 3;
        else
            return z > 0.0 ? 2 : 5;
    } else {
        if (ay > az)
            return y > 0.0 ? 1 : 4;
        else
            return z > 0.0 ? 2 : 5;
    }
}
