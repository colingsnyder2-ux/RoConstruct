// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oi /Ot /Oy /GF /GS- /EHsc /MT
namespace G3D {
class Matrix3 { public: float elt[3][3]; Matrix3() {} Matrix3(const Matrix3& m) { *this = m; } Matrix3& operator=(const Matrix3& m); };
class Vector3 { public: float x, y, z;
    Vector3(float a, float b, float c) : x(a), y(b), z(c) {}
    Vector3(const Vector3& v) { x = v.x; y = v.y; z = v.z; } };
class CoordinateFrame {
public:
    Matrix3 rotation; Vector3 translation;
    CoordinateFrame(const Matrix3& r, const Vector3& t) : rotation(r), translation(t) {}
    ~CoordinateFrame() {}
};
}
namespace RBX { enum NormalId { NORM_X = 0 }; const G3D::Matrix3& normalIdToMatrix3(NormalId id); }
G3D::CoordinateFrame g_frame(RBX::normalIdToMatrix3((RBX::NormalId)0), G3D::Vector3(1.0f, 0.5f, 0.0f));
