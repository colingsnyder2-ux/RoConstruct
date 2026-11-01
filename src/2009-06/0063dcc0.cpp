// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z; Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
class Matrix3 { public: float elt[3][3]; Matrix3(const Matrix3& m); };
class CoordinateFrame {
public:
    Matrix3 rotation;
    Vector3 translation;
    CoordinateFrame(const Matrix3& r, const Vector3& t) : rotation(r), translation(t) {}
};
}
using namespace G3D;
class PVInstance {
public:
    char pad[0xc4];
    CoordinateFrame cframe;
    void setCoordinateFrame(const CoordinateFrame& cf);
    void setPosition(const Vector3& p);
};
void PVInstance::setPosition(const Vector3& p)
{
    setCoordinateFrame(CoordinateFrame(cframe.rotation, p));
}
