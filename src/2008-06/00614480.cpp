// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;

    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Cofm {
    const Vector3& getCofmInBody() const;
};

struct Frame {
    char data[0x24];
    Vector3 transform(const Vector3&) const;
};

struct S {
    char reserved0[0x28];
    Cofm* cofm;
    char reserved1[0x68];
    Frame frame;
    Vector3 fallback;

    const void* get();
    Vector3 f();
};

Vector3 S::f()
{
    return cofm
        ? (get(), frame.transform(cofm->getCofmInBody()))
        : (get(), fallback);
}
