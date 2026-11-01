// from server: 100% by king_originala
#pragma float_control(precise, off)

struct Vector3 {
    float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3 operator-(const Vector3&) const;
};

inline Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);
}

struct AxisAlignedBox {
    unsigned char data[32];
};

struct Camera;

struct Sphere {
    float radius;
    Vector3 center;
};

extern void (__thiscall *mergeBox)(AxisAlignedBox*, const AxisAlignedBox&);
extern const Vector3& (__thiscall *derivedPosition)(const Camera*);
extern float (__thiscall *vectorLength)(const Vector3*);

template<class T>
inline const T& minimum(const T& a, const T& b)
{
    return b < a ? b : a;
}

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

struct S : AxisAlignedBox {
    float nearest;
    float farthest;
    void f(const AxisAlignedBox&, const Sphere&, const Camera&);
};

void S::f(const AxisAlignedBox& box, const Sphere& sphere,
          const Camera& camera)
{
    mergeBox(this, box);
    Vector3 delta = derivedPosition(&camera) - sphere.center;
    float distance = vectorLength(&delta);
    nearest = minimum(nearest, maximum(0.0f, distance - sphere.radius));
    farthest = maximum(farthest, distance + sphere.radius);
}
