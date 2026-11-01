// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D {
struct Vector3 {
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3 operator-(const Vector3& o) const { return Vector3(x - o.x, y - o.y, z - o.z); }
    float magnitude() const { return sqrtf(x * x + y * y + z * z); }
};
struct Matrix3 { float m[3][3]; };
struct CoordinateFrame { Matrix3 rotation; Vector3 translation; };
}
namespace RBX {
class Camera {
public:
    char pad[0xdc];
    G3D::CoordinateFrame cameraGoal;
    G3D::CoordinateFrame cameraFocus;
    bool canZoom(int direction) const;
};
bool Camera::canZoom(int direction) const
{
    G3D::Vector3 v = cameraGoal.translation - cameraFocus.translation;
    float distance = sqrtf(v.x * v.x + (v.y * v.y + v.z * v.z));
    if (direction > 0) return distance > 0.5f;
    return distance < 1000.0f;
}
}
