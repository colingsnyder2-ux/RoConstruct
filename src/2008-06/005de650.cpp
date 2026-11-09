// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
#include <math.h>
namespace G3D { class Vector3 { public: float x, y, z; Vector3() {} Vector3(float a, float b, float c) : x(a), y(b), z(c) {} }; }
namespace RBX { namespace Math { G3D::Vector3 vectorAbs(const G3D::Vector3& v);
G3D::Vector3 vectorAbs(const G3D::Vector3& v) { return G3D::Vector3(fabs(v.x), fabs(v.y), fabs(v.z)); }
float getHeading(const G3D::Vector3& v) { return atan2(-v.x, -v.z); } } }
