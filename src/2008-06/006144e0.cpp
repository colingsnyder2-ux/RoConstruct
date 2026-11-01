// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
};

struct Rotation {
    float data[9];
};

struct Frame {
    Rotation rotation;
    Vector3 translation;
    Frame(const Rotation&);
};

struct S {
    char reserved[0x94];
    Rotation rotation;

    const void* get();
    const Vector3& getCofmInBody(Vector3&) const;
    Frame f();
};

Frame S::f()
{
    get();
    Vector3 temporary;
    const Vector3& position = getCofmInBody(temporary);
    Frame result(rotation);
    result.translation.x = position.x;
    result.translation.y = position.y;
    result.translation.z = position.z;
    return result;
}
