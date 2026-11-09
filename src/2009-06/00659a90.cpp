// from server: 95% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast

namespace G3D {
struct Vector3
{
    float x, y, z;
    Vector3() {}
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; }
    Vector3 operator-(const Vector3& v) const { return Vector3(x - v.x, y - v.y, z - v.z); }
    Vector3 operator*(float f) const { return Vector3(x * f, y * f, z * f); }
};
struct Matrix3
{
    float elt[3][3];
    Vector3 getColumn(int i) const;
};
struct CoordinateFrame
{
    Matrix3 rotation;
    Vector3 translation;
    Vector3 lookVector() const { return rotation.getColumn(2) * -1.0f; }
};
}

namespace RBX {
extern float cameraDistanceScale;
struct Math
{
    static void setYawPitch(G3D::Matrix3& m, float yaw, float pitch);
};

class Camera
{
    char pad[0xdc];
    G3D::CoordinateFrame cameraGoal;
    G3D::CoordinateFrame cameraFocus;
public:
    void setYawPitch(float yaw, float pitch, float distance);
};

void Camera::setYawPitch(float yaw, float pitch, float distance)
{
    Math::setYawPitch(cameraGoal.rotation, yaw, pitch);
    float d = cameraDistanceScale;
    cameraGoal.translation = cameraFocus.translation - cameraGoal.rotation.getColumn(2) * d * cameraDistanceScale;
}
}
