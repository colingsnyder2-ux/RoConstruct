// from server: 100% by tester
struct Vector3 { float x, y, z; };

struct Body {
    char pad[0xb8];
    Vector3 value;
    void updatePV();
};

struct PartInstance {
    char pad[0x2c8];
    Body* body;
    const Vector3& getValue();
};

const Vector3& PartInstance::getValue()
{
    Body* b = body;
    b->updatePV();
    return b->value;
}
