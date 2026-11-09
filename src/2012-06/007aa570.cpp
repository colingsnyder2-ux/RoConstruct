// from server: 100% by tajop
struct Vector3 {
    float x, y, z;
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
};

struct S {
    char pad[0x194];
    float x, y, z;
    Vector3 f() const;
};

Vector3 S::f() const
{
    return Vector3(x, y, z);
}
