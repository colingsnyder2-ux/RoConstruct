// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
class Math {
public:
    static inline bool isNanInf(float f) { return ((*(int*)&f) & 0x7f800000) == 0x7f800000; }
    static bool isNanInfVector3(const G3D::Vector3& v);
};
bool Math::isNanInfVector3(const G3D::Vector3& v)
{
    return isNanInf(v.x) || isNanInf(v.y) || isNanInf(v.z);
}
}
