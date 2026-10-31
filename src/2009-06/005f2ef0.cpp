// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Matrix3 { public: float e[9]; Matrix3(const Matrix3& o); };
class Vector3 { public: float x, y, z;
    Vector3(const Vector3& o) : x(o.x), y(o.y), z(o.z) {} };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
namespace RBX {
class Base0 { public: virtual ~Base0(); char pad[0x230]; };
class IHasLocation { public: virtual const G3D::CoordinateFrame getLocation() const = 0; };
class PartInstance : public Base0, public IHasLocation {
public:
    const G3D::CoordinateFrame& getCoordinateFrame() const;
    virtual const G3D::CoordinateFrame getLocation() const;
};
const G3D::CoordinateFrame PartInstance::getLocation() const
{
    return getCoordinateFrame();
}
}
