// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
class Matrix3 { public: float elt[3][3]; };
class Vector3 {
public:
    float x, y, z;
    Vector3& operator=(const Vector3& o) { x = o.x; y = o.y; z = o.z; return *this; }
};
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame& operator=(const CoordinateFrame& o) { rotation = o.rotation; translation = o.translation; return *this; }
};
}
namespace RBX {
class Camera {
public:
    char pad[0xd0];
    G3D::CoordinateFrame cf;
    void setCoordinateFrame(const G3D::CoordinateFrame& value);
};
void Camera::setCoordinateFrame(const G3D::CoordinateFrame& value)
{
    cf = value;
}
}
