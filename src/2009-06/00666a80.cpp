// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z;
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
class Color3 { public: float r, g, b; static const Color3& green(); };
class Matrix3 { public: float elt[3][3];
    Matrix3(const Matrix3& m);
    static const Matrix3& identity(); };
class CoordinateFrame { public:
    Matrix3 rotation; Vector3 translation;
    CoordinateFrame(const Vector3& _translation) : rotation(Matrix3::identity()), translation(_translation) {}
    ~CoordinateFrame() {} };
}
namespace RBX {
class Adorn;
class DrawAdorn { public:
    static void cylinder(Adorn* adorn, const G3D::CoordinateFrame& worldC, int axis, float length, float radius, const G3D::Color3& color, int exe2009 = 1);
};
class Humanoid { public:
    static void renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint);
};
void Humanoid::renderWaypoint(Adorn* adorn, const G3D::Vector3& waypoint)
{
    DrawAdorn::cylinder(adorn, G3D::CoordinateFrame(waypoint), 1, 0.2f, 1.0f, G3D::Color3::green());
}
}
