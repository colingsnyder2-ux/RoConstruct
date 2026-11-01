// from server: 100% by king_originala
struct Vec3 {
    float x, y, z;
};

extern int indices[][4];

struct S {
    char padding[4];
    Vec3 vertices[8];

    void f(int index, Vec3& a, Vec3& b, Vec3& c, Vec3& d);
};

void S::f(int index, Vec3& a, Vec3& b, Vec3& c, Vec3& d)
{
    const Vec3& v0 = vertices[indices[index][0]];
    a.x = v0.x;
    a.y = v0.y;
    a.z = v0.z;

    const Vec3& v1 = vertices[indices[index][1]];
    b.x = v1.x;
    b.y = v1.y;
    b.z = v1.z;

    const Vec3& v2 = vertices[indices[index][2]];
    c.x = v2.x;
    c.y = v2.y;
    c.z = v2.z;

    const Vec3& v3 = vertices[indices[index][3]];
    d.x = v3.x;
    d.y = v3.y;
    d.z = v3.z;
}
