// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 { public: Matrix3(const Matrix3&); float m[9]; };
class Vector3 { public: float x, y, z; Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame();
};
}
struct Primitive { const G3D::CoordinateFrame& getCoordinateFrame() const; };
struct Base1 { virtual void a(); char pad[0x258]; };
struct Base2 { virtual G3D::CoordinateFrame getLocation() = 0; };
struct Derived : Base1, Base2 {
    Primitive* getPrimitive();
    virtual G3D::CoordinateFrame getLocation();
};
G3D::CoordinateFrame Derived::getLocation()
{
    if (Primitive* p = getPrimitive())
        return p->getCoordinateFrame();
    return G3D::CoordinateFrame();
}
