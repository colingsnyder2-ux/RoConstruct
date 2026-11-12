// from server: 97% by EspClaude
// roc-flags: /O2 /GS /EHsc /MD /fp:fast
// roc 2007-08 00599850  unit: RBX::VCamera::?$FactoryProduct  size: 310 bytes
// Camera zoom: offsets 0x150/0x180 (Vector3 at cframe translation / focus translation),
// limits 0.25f (0x787050) and 1000.0f (0x7b1548), out-of-line Vector3::operator/(float) at 0x50f630,
// 0x599480 returns object whose vtable slot 0xc is called.
#include <math.h>
#include <algorithm>

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
    Vector3 operator-(const Vector3& o) const { return Vector3(x - o.x, y - o.y, z - o.z); }
    Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); }
    Vector3 operator/(float s) const;
    float length() const { return (float)::sqrt((double)(x * x + y * y + z * z)); }
};

struct Listener {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void onChanged();
};

class Camera {
public:
    char pad0[0x150];
    Vector3 translation;
    char pad1[0x180 - 0x15c];
    Vector3 focus;

    Listener* getListener();
    bool zoom(float distance);
};

bool Camera::zoom(float distance)
{
    Vector3 look = focus - translation;
    float currentDistance = look.length();
    float minDistance = 0.25f;
    float maxDistance = 1000.0f;
    if (distance < minDistance && currentDistance == minDistance)
        return false;
    if (distance > maxDistance && currentDistance == maxDistance)
        return false;
    distance = std::max(minDistance, distance);
    distance = std::min(maxDistance, distance);
    translation = focus - (look * distance) / currentDistance;
    if (Listener* l = getListener())
        l->onChanged();
    return true;
}
