// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3&);
};

inline Vector3::Vector3(const Vector3& v)
    : x(v.x), y(v.y), z(v.z) {
}

struct Matrix3 {
    float values[9];
    Matrix3(const Matrix3&);
};

struct Frame {
    Matrix3 rotation;
    Vector3 translation;
};

struct Body {
    char pad[0x94];
    Vector3 value;
    void updatePV();
};

struct Primitive {
    char pad[0xa0];
    Body* body;
    const Vector3& getValue();
};

struct S {
    Frame f();
};

Frame S::f() {
    Primitive* primitive =
        reinterpret_cast<Primitive*>(reinterpret_cast<char*>(this) - 0x1cc);
    return *reinterpret_cast<const Frame*>(&primitive->getValue());
}
