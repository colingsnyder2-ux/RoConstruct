// from server: 100% by EspClaude
// roc 2007-08 0062f100  RBX::AdornG3D helper: scale from distance between two points (G3D Vector3 ops)
#include <math.h>

class Vector3 {
public:
    float x, y, z;
    Vector3() {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    float length() const { return sqrtf(x * x + y * y + z * z); }
};

float __cdecl distanceTo(const Vector3& a, const Vector3& b) {
    float len = (a - b).length();
    float result = 0.5f;
    if (len > 28.66242027282715) {
        result = (float)(len * 0.017444444820284843);
    }
    return result;
}
