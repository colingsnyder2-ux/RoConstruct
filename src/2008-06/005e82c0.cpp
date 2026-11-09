// from server: 100% by tester
struct Vector3 { float x, y, z; };

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

const Vector3& Primitive::getValue()
{
    Body* b = body;
    b->updatePV();
    return b->value;
}
