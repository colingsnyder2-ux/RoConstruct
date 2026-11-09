// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 { public: Matrix3(const Matrix3& m); float e[9]; };
class Vector3 { public: Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} float x, y, z; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
namespace RBX {
namespace Math { bool isLegalCoord(const G3D::CoordinateFrame& c); }
class Frame { public: void set(const G3D::CoordinateFrame& c); };
class Camera {
public:
    char pad[0x98];
    Frame frame;
    char pad2[0xdc - 0x99];
    G3D::CoordinateFrame cameraGoal;
    void updateGoal(double dt);
    void step(double dt);
};
void Camera::step(double dt)
{
    updateGoal(dt);
    G3D::CoordinateFrame goal = cameraGoal;
    if (Math::isLegalCoord(goal))
        frame.set(goal);
}
}
