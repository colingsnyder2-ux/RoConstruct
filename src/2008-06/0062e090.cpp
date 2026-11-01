// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct S {
    char pad[360];
    float x, y, z;
    Vector3 f();
};

Vector3 S::f()
{
    Vector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
}
