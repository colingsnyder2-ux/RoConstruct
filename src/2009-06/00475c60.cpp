// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D {
class Vector3 { public: float x, y, z;
  inline Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {} };
class Matrix3 { public: float elt[3][3]; };
class CoordinateFrame { public: Matrix3 rotation; Vector3 translation; };
}
G3D::Vector3 getTranslation(const G3D::CoordinateFrame& c)
{
    return c.translation;
}
