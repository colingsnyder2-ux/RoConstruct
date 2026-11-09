// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
namespace G3D { class Vector3 { public: float x, y, z; Vector3() {} Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
 Vector3 operator*(float s) const { return Vector3(x * s, y * s, z * s); } }; }
namespace RBX { G3D::Vector3 scaleBy20(const G3D::Vector3& v) { return v * 20.0f; } }
