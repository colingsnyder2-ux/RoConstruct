// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
};

struct Object {
    char padding[0x90];
    Vector3 value;
};

struct Holder {
    char padding[0x2c];
    Object* object;
};

struct S {
    char padding[0x10];
    Holder* holder;
    const Vector3& f();
};

const Vector3& S::f()
{
    Object* object = holder->object;
    if (object)
        return object->value;

    static Vector3 zero;
    return zero;
}
