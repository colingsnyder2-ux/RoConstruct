// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Matrix3 {
    float m[3][3];
};

struct Ray {
    unsigned int tag;
    Vector3 origin;
    Vector3 direction;
};

Ray* __cdecl makeRay(Ray* result, const Vector3* origin,
                    const Vector3* direction);

inline void multiply(Vector3& r, const Matrix3& a, const Vector3& v) {
    r.x = a.m[0][0] * v.x
        + (a.m[0][1] * v.y + a.m[0][2] * v.z);
    r.y = a.m[1][0] * v.x
        + (a.m[1][1] * v.y + a.m[1][2] * v.z);
    r.z = a.m[2][0] * v.x
        + (a.m[2][1] * v.y + a.m[2][2] * v.z);
}

struct S {
    float m[3][3];
    Vector3 translation;

    Matrix3* transpose(Matrix3* result) const;
    Ray* transform(Ray* result, const Ray& ray) const;
};

Ray* S::transform(Ray* result, const Ray& ray) const {
    volatile int zero = 0;
    Matrix3 storage;
    Vector3 direction;
    multiply(direction, *transpose(&storage), ray.direction);

    double x = double(ray.origin.x) - translation.x;
    double y = double(ray.origin.y) - translation.y;
    double z = double(ray.origin.z) - translation.z;

    Vector3 origin;
    origin.x = float(m[2][0] * z + m[1][0] * y + m[0][0] * x);
    origin.y = float(m[2][1] * z + m[1][1] * y + m[0][1] * x);
    origin.z = float(m[2][2] * z + m[1][2] * y + m[0][2] * x);

    makeRay(result, &origin, &direction);
    return result;
}
