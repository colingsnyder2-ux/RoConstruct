// from server: 100% by king_originala
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
};

struct Body {
    char pad[4];
    Vector3 value;
};

struct PartInstance {
    char pad[0x2c4];
    Body* body;
    Vector3 getValue();
};

Vector3 PartInstance::getValue()
{
    return body->value;
}
