// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include <math.h>

// INFERRED: the original was built with /fp:fast semantics (inline fsqrt, no float spills),
// but the fixed flag line has no /fp:fast, so request it for this translation unit.
#pragma float_control(precise, off)

// INFERRED: minimal local G3D::Vector3 / G3D::Line layout (no native header available).
namespace G3D {

class Vector3 {
public:
    float x, y, z;
    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}

    Vector3& operator=(const Vector3& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    float squaredMagnitude() const {
        return x * x + y * y + z * z;
    }

    Vector3 direction() const {
        const float lenSquared = squaredMagnitude();
        const float invSqrt = 1.0f / (float)sqrt((double)lenSquared);
        return Vector3(x * invSqrt, y * invSqrt, z * invSqrt);
    }
};

class Line {
protected:
    Vector3 _point;
    Vector3 _direction;

    Line(const Vector3& point, const Vector3& direction);

public:
    virtual ~Line();
};

Line::Line(const Vector3& point, const Vector3& direction) {
    _point = point;
    _direction = direction.direction();
}

}
