// from server: 100% by EspClaude
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z;
    inline Vector3& operator=(const Vector3& v) { x = v.x; y = v.y; z = v.z; return *this; } };
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    void lookAt(const Vector3& target);
};
}
namespace RBX {
class Camera {
public:
    void lookAt(const G3D::Vector3& point);
private:
    char pad[0xdc];
    G3D::CoordinateFrame cameraGoal;
    G3D::CoordinateFrame cameraFocus;
};
void Camera::lookAt(const G3D::Vector3& point)
{
    cameraFocus.translation = point;
    cameraGoal.lookAt(point);
}
}
