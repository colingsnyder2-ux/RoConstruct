// from server: 100% by king_originala
struct Matrix {
    float values[9];
};

struct Transform {
    Matrix rotation;
    float x, y, z;
    Transform& operator=(const Transform& value);
};

__forceinline Transform& Transform::operator=(const Transform& value)
{
    rotation = value.rotation;
    x = value.x;
    y = value.y;
    z = value.z;
    return *this;
}

struct S_func_005834c0 {
    char pad0[432];
    Transform transform;
    void f(const Transform& value);
};

void S_func_005834c0::f(const Transform& value)
{
    transform = value;
}
