// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
#include <math.h>
namespace G3D {
class Vector2 {
public:
    float x, y;
    Vector2() {}
    Vector2(float _x, float _y) : x(_x), y(_y) {}
    float length() const { return sqrtf(x * x + y * y); }
    Vector2 operator*(float s) const { return Vector2(x * s, y * s); }
    Vector2 operator/(float k) const { return *this * (1.0f / k); }
    Vector2 direction() const { return *this / length(); }
};
class Vector2int16 { public: short x, y; };
class Vector3 {
public:
    float x, y, z;
    Vector2 yz() const;
};
}
using namespace G3D;
void CylinderAlongXTransform(Vector3& vertex, Vector3& normal, Vector2& tex, const Vector2& radius, const Vector2int16& ivertex)
{
    Vector2 n = vertex.yz().direction();
    vertex.y = radius.x * n.x;
    vertex.z = radius.y * n.y;
    normal.x = 0.0f;
    normal.y = n.x;
    normal.z = n.y;
}
