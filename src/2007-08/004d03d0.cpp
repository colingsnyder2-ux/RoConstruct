// from server: 100% by EspClaude
// roc 2007-08 004d03d0  slow-moving test: part state == 1 and max |linear velocity| < 30
struct Vector3 {
    float x, y, z;
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {}
};

struct PartInstance {
    char pad0[0x18c];
    int state;
    const Vector3& getLinearVelocity() const;
};

float maxAbs(const Vector3& v);

struct TextureProxyBase {
    char pad0[0xb0];
    PartInstance* part;
    char pad1[0xc8 - 0xb4];
    void* pending;
    bool check();
};

bool TextureProxyBase::check()
{
    if (pending == 0 && part->state == 1) {
        Vector3 v = part->getLinearVelocity();
        return maxAbs(v) < 30.0;
    }
    return false;
}
