// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D {
class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3& operator+=(const Vector3& v) { x += v.x; y += v.y; z += v.z; return *this; }
    Vector3 cross(const Vector3& r) const { return Vector3(y * r.z - z * r.y, z * r.x - x * r.z, x * r.y - y * r.x); }
};
}
namespace RBX {
class Body;
class SimBody {
    void update();
    void updateIfDirty() { if (dirty) update(); }
public:
    Body* body;
    float dt;
    bool dirty;
    float rotation[9];
    G3D::Vector3 translation;
    char rest[0x9c - 0x3c];
    G3D::Vector3 force;
    G3D::Vector3 torque;
    static G3D::Vector3 accumulateInline(const G3D::Vector3& _force, const G3D::Vector3& pvWorld, const G3D::Vector3& worldPos)
    {
        G3D::Vector3 temp = worldPos - pvWorld;
        return temp.cross(_force);
    }
    void accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos);
};
void SimBody::accumulateForce(const G3D::Vector3& _force, const G3D::Vector3& worldPos)
{
    updateIfDirty();
    force += _force;
    torque += accumulateInline(_force, translation, worldPos);
}
}
