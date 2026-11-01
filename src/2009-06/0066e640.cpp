// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX {
class Math {
public:
    static bool isDenormal(float f);
    static bool fixDenorm(G3D::Vector3& v);
};
inline int fpclass(float f)
{
    unsigned int b = *(unsigned int*)&f & 0x7fffffff;
    if (b <= 0x7fffff)
        return b ? 4 : 0;
    if (b < 0x7f800000)
        return 1;
    return (b & 0x7fffff) ? 3 : 2;
}
__declspec(noinline) bool Math::isDenormal(float f)
{
    return fpclass(f) == 4;
}
bool Math::fixDenorm(G3D::Vector3& v)
{
    bool fixed = false;

    float x = v.x;
    if (Math::isDenormal(x))
    {
        v.x = 0;
        fixed = true;
    }

    float y = v.y;
    if (Math::isDenormal(y))
    {
        v.y = 0;
        fixed = true;
    }

    float z = v.z;
    if (Math::isDenormal(z))
    {
        v.z = 0;
        fixed = true;
    }

    return fixed;
}
}
