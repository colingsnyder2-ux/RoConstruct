// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3
{
    float x, y, z;
};

struct Geometry
{
    char padding[4];
    Vector3 size;
};

struct Part
{
    char padding[0x9c];
    Geometry* geometry;
};

struct Transform
{
    char data[0x30];
};

extern int __cdecl normalId(const Transform*);
extern int __cdecl normalIdOpposite(int);
extern const float radiusScale;

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

template<class T>
inline const T& minimum(const T& a, const T& b)
{
    return a < b ? a : b;
}

struct RotatePJoint
{
    char padding0[0x0c];
    Part* part0;
    Part* part1;
    char padding1[0x14];
    Transform frame0;
    Transform frame1;

    float radius();
};

float RotatePJoint::radius()
{
    const Vector3& size0 = part0->geometry->size;
    float a[3] = { size0.x, size0.y, size0.z };

    const Vector3& size1 = part1->geometry->size;
    float b[3] = { size1.x, size1.y, size1.z };

    int axis0 = normalId(&frame0);
    int axis1 = normalIdOpposite(normalId(&frame1));

    int b1 = (axis1 + 1) % 3;
    int b2 = (axis1 + 2) % 3;
    int a2 = (axis0 + 2) % 3;
    int a1 = (axis0 + 1) % 3;

    float maximum0 = maximum(a[a1], a[a2]);
    float maximum1 = maximum(b[b1], b[b2]);

    float result = minimum(maximum1, maximum0);
    return result * radiusScale;
}
